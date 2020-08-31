/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : message_queue.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/24
*  Last Modified :
*  Description   : message queue
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/4/24
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

#ifndef __MESSAGE_QUEUE_H__
#define __MESSAGE_QUEUE_H__


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <condition_variable>
#include <list>
#include <mutex>

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/

typedef enum
{
	HIGH_PRIORITY,
	MID_PRIORITY,
	LOW_PRIORITY
} MessagePriority;


template <typename T>
class Message
{
private:
	T m_id;
	MessagePriority m_priority;
	Message() {}

public:
	void* arg1; //be careful for its lifetime
	void* arg2;
	void* arg3;

	static Message<T>* create(T id, MessagePriority priority = MID_PRIORITY)
	{
		Message<T>* m = new Message<T>();
		if (!m)
			return nullptr;
		m->m_id = id;
		m->m_priority = priority;
		m->arg1 = NULL;
		m->arg2 = NULL;
		m->arg3 = NULL;
		return m;
	}
	inline T GetID()
	{
		return m_id;
	}
	inline MessagePriority GetPriority()
	{
		return m_priority;
	}
	bool PriorityHighThan(Message& msg)
	{
		return m_priority < msg.GetPriority();
	}
	bool PriorityLowOrEqual(Message& msg)
	{
		return m_priority >= msg.GetPriority();
	}
};



template <typename T>
class MessageQueue
{
private:
	std::mutex mtx;
	std::condition_variable cond;
	std::list<Message<T>*> msg_list;

public:
	MessageQueue() {}
	~MessageQueue()
	{
		assert(msg_list.empty());
	}

	void Push(Message<T>* msg, bool signal = false)
	{
		std::unique_lock<std::mutex> lk(mtx);
#if 0
		//带优先级
		if(!msg_list.empty()) {
			Message<T> &m = msg_list.back();
			if(msg.PriorityLowOrEqual(m)) {
				msg_list.push_back(msg);
				goto out;
			}
			for(std::list<Message<T>>::iterator i = msg_list.begin(); i != msg_list.end(); i++) {
				Message<T> &m = *i;
				if(msg.PriorityHighThan(m)) {
					msg_list.insert(i, msg);
					goto out;
				}
			}
			assert(0);
		} else {
			msg_list.push_back(msg);
		}
#else
		msg_list.push_back(msg);
#endif
out:
		if (signal)
		{
			cond.notify_one();
		}
	}

	Message<T>* PopFront()
	{
		std::unique_lock<std::mutex> lk(mtx);
		assert(!msg_list.empty());
		Message<T>* msg = msg_list.front();
		msg_list.pop_front();
		return msg;
	}

	void PopMessageOfId(T id, std::list<Message<T>*>& store_list)
	{
		std::unique_lock<std::mutex> lk(mtx);
		if (msg_list.empty())
			return;

		auto it = msg_list.begin();
		for (; it != msg_list.end();)
		{
			Message<T>* m = *it;
			if (m->GetID() == id)
			{
				it = msg_list.erase(it);
				store_list.push_back(m);
				continue;
			}
			it++;
		}
	}

	bool Empty()
	{
		std::unique_lock<std::mutex> lk(mtx);
		return msg_list.empty();
	}
	int size()
	{
		std::unique_lock<std::mutex> lk(mtx);
		return msg_list.size();
	}
	void WaitMessage()
	{
		std::unique_lock<std::mutex> lk(mtx);

		/* wait先检查lambda表达式，如果满足条件则返回。否则就等待，此时unlock mut然后线程阻塞。
		当线程被唤醒，会重新lock mut，并检查lambda表达式。如果lambda不满足，那么unlock
		mut继续等待。	所以上面要有unique_lock		*/
		cond.wait(lk, [this]{return !msg_list.empty();});
	}
	void clear()
	{
		std::unique_lock<std::mutex> lk(mtx);
		for (Message<T>* m : msg_list)
		  delete m;

		msg_list.clear();
	}
};


#endif /* __MESSAGE_QUEUE_H__ */




