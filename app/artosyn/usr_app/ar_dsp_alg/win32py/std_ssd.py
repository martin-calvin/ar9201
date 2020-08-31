
import cv2
import os


from ctypes import *
from ar_cdnn import AR_CDNN

#CDNN RESLUT STRUCT FOR SSD ONLY

RESIZE_WIDTH = 300
RESIZE_HEIGHT = 300

class AR_RECT_st(Structure):
	_fields_=[  ("x",c_int),
		    ("y",c_int),
		    ("width",c_int),
		    ("height",c_int)
		]
	
class AR_DSP_DETECT_OBJ_st(Structure):
    _fields_=[  ("index",c_int),
                ("label_index",c_int),
                ("label",c_char*256),
                ("score",c_float),
                ("rect",AR_RECT_st)
             ]

class AR_DSP_DETECT_RESULTS_st(Structure):
    _fields_=[  ("object_num",c_int),
                ("objects",AR_DSP_DETECT_OBJ_st*64)
             ]



ar_rect_sub = AR_RECT_st()
ar_rect_sub.x = 0
ar_rect_sub.y = 0
ar_rect_sub.width = 0
ar_rect_sub.height = 0


ar_dsp_detect_obj = AR_DSP_DETECT_OBJ_st()
ar_dsp_detect_obj.index = 0;   
ar_dsp_detect_obj.label_index= 0
ar_dsp_detect_obj.label = bytes(0);   
ar_dsp_detect_obj.score= 0
ar_dsp_detect_obj.rect = ar_rect_sub  


ar_dsp_detect_result = AR_DSP_DETECT_RESULTS_st()
ar_dsp_detect_result.object_num = 0;
ar_dsp_detect_result.objects = (AR_DSP_DETECT_OBJ_st*64)()



if __name__ == '__main__':
   
    ar_cdnn = AR_CDNN()

    run_mode =1
    ip_addr = bytes("192.168.199.201",'utf-8')
    ar_cdnn.Init(run_mode, ip_addr)

       
    wght_path =  bytes("..\\win32file\\std_ssd_v3.cdnnQdata",'utf-8')
    ar_cdnn.ConfigDSP(wght_path) 

     

    result_file =bytes("..\\win32file\\ssd_result_py.txt", 'utf-8')
    rf = open(result_file, "a")
    
    img_path = bytes("..\\win32file\\ssd_test_img\\", 'utf-8')
    img_dir = os.listdir(img_path)  
    for f in img_dir:

            rf.write(str(f, encoding ="utf-8"))
            rf.write("\n")
            
            image = str(img_path+f, encoding ="utf-8")
            
            orig_img = cv2.imread(image)
            img = cv2.cvtColor(orig_img, cv2.COLOR_BGR2RGB)
            img = cv2.resize(img, (RESIZE_WIDTH, RESIZE_HEIGHT), interpolation=cv2.INTER_CUBIC)
            
            ar_cdnn.DoAlgrithom(img)

            result = ar_cdnn.GetResult()

            print("inference cycles:%d" %(result.statistics.cdnn_inference_time))
            print("postprocess cycles:%d" %(result.statistics.cdnn_post_proc_time))

            num = result.output.output_buffer[0].height
            object_num = 0 
            for i in range(num):
                
                if result.output.output_buffer[0].pdata[i] < float(1.0) or result.output.output_buffer[0].pdata[i] > 21:
                        continue
                if result.output.output_buffer[1].pdata[i] < float(0.6):
                        continue
                ar_dsp_detect_result.objects[object_num].label_index = int(result.output.output_buffer[0].pdata[i]);
                ar_dsp_detect_result.objects[object_num].score = result.output.output_buffer[1].pdata[i * 5];
                ar_dsp_detect_result.objects[object_num].rect.x = int(result.output.output_buffer[1].pdata[i * 5 + 1] * RESIZE_WIDTH);
                ar_dsp_detect_result.objects[object_num].rect.y = int(result.output.output_buffer[1].pdata[i * 5 + 2] * RESIZE_HEIGHT);
                ar_dsp_detect_result.objects[object_num].rect.width = int(result.output.output_buffer[1].pdata[i * 5 + 3] * RESIZE_WIDTH) - ar_dsp_detect_result.objects[object_num].rect.x +1
                ar_dsp_detect_result.objects[object_num].rect.height = int(result.output.output_buffer[1].pdata[i * 5 + 4] * RESIZE_HEIGHT) - ar_dsp_detect_result.objects[object_num].rect.y + 1;

                if ar_dsp_detect_result.objects[object_num].rect.x < 0:
                        ar_dsp_detect_result.objects[object_num].rect.x = 0
                if ar_dsp_detect_result.objects[object_num].rect.x > orig_img.shape[1]:
                        ar_dsp_detect_result.objects[object_num].rect.x = orig_img.shape[1]

                if ar_dsp_detect_result.objects[object_num].rect.y < 0:
                        ar_dsp_detect_result.objects[object_num].rect.y = 0
                if ar_dsp_detect_result.objects[object_num].rect.y > orig_img.shape[0]:
                        ar_dsp_detect_result.objects[object_num].rect.y = orig_img.shape[0]

                if ar_dsp_detect_result.objects[object_num].rect.width < 0:
                        ar_dsp_detect_result.objects[object_num].rect.width = 0
                if ar_dsp_detect_result.objects[object_num].rect.width > orig_img.shape[1]:
                        ar_dsp_detect_result.objects[object_num].rect.width = orig_img.shape[1]

                if ar_dsp_detect_result.objects[object_num].rect.height < 0:
                        ar_dsp_detect_result.objects[object_num].rect.height = 0
                if ar_dsp_detect_result.objects[object_num].rect.height > orig_img.shape[0]:
                        ar_dsp_detect_result.objects[object_num].rect.height = orig_img.shape[0]
                        

                object_num = object_num + 1; 
                ar_dsp_detect_result.object_num = object_num

            for i in range(ar_dsp_detect_result.object_num):  
                print("[DSP%d][%d]: %f, [%d, %d],[%d, %d] " %(0, ar_dsp_detect_result.objects[i].label_index,
                                                           ar_dsp_detect_result.objects[i].score, ar_dsp_detect_result.objects[i].rect.x,
                                                           ar_dsp_detect_result.objects[i].rect.y,
                                                           ar_dsp_detect_result.objects[i].rect.x + ar_dsp_detect_result.objects[i].rect.width,
                                                           ar_dsp_detect_result.objects[i].rect.y + ar_dsp_detect_result.objects[i].rect.height))

                rf.write("[DSP%d][%d]: %f, [%d, %d],[%d, %d] \n" %(0, ar_dsp_detect_result.objects[i].label_index,
                                                                  ar_dsp_detect_result.objects[i].score,
                                                                  ar_dsp_detect_result.objects[i].rect.x,ar_dsp_detect_result.objects[i].rect.y,
                                                                  ar_dsp_detect_result.objects[i].rect.x + ar_dsp_detect_result.objects[i].rect.width,
                                                                  ar_dsp_detect_result.objects[i].rect.y + ar_dsp_detect_result.objects[i].rect.height))



rf.close()

  


