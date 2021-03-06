/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "ar_dsp_rpc.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif
union {
	AR_DSP_CFG_RPC_st ar_alg_cfg_dsp_1_arg;
	AR_DSP_ALG_RPC_IN_st ar_do_algrithom_1_arg;
	AR_DSP_ALG_TO_RPC_IN_st ar_do_algrithom_with_timeout_1_arg;
	AR_FILE_CHUNK_st ar_send_file_1_arg;
} argument;

static void
ar_dsp_rpc_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{

	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case AR_ALG_CFG_DSP:
		_xdr_argument = (xdrproc_t) xdr_AR_DSP_CFG_RPC_st;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) ar_alg_cfg_dsp_1_svc;
		break;

	case AR_DO_ALGRITHOM:
		_xdr_argument = (xdrproc_t) xdr_AR_DSP_ALG_RPC_IN_st;
		_xdr_result = (xdrproc_t) xdr_AR_DSP_ALG_RPC_OUT_st;
		local = (char *(*)(char *, struct svc_req *)) ar_do_algrithom_1_svc;
		break;

	case AR_DO_ALGRITHOM_WITH_TIMEOUT:
		_xdr_argument = (xdrproc_t) xdr_AR_DSP_ALG_TO_RPC_IN_st;
		_xdr_result = (xdrproc_t) xdr_AR_DSP_ALG_RPC_OUT_st;
		local = (char *(*)(char *, struct svc_req *)) ar_do_algrithom_with_timeout_1_svc;
		break;

	case AR_SEND_FILE:
		_xdr_argument = (xdrproc_t) xdr_AR_FILE_CHUNK_st;
		_xdr_result = (xdrproc_t) xdr_int;
		local = (char *(*)(char *, struct svc_req *)) ar_send_file_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

extern int ar_alg_rpc_svr_init();
extern int ar_alg_rpc_svr_deinit();

int
main (int argc, char **argv)
{
	register SVCXPRT *transp;

	pmap_unset (AR_DSP_RPC_PROG, VERSION);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, AR_DSP_RPC_PROG, VERSION, ar_dsp_rpc_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (AR_DSP_RPC_PROG, VERSION, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, AR_DSP_RPC_PROG, VERSION, ar_dsp_rpc_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (AR_DSP_RPC_PROG, VERSION, tcp).");
		exit(1);
	}

	ar_alg_rpc_svr_init();
	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	ar_alg_rpc_svr_deinit();
	exit (1);
	/* NOTREACHED */
}
