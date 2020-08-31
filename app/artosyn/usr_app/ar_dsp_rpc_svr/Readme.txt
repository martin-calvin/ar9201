1. rpcgen -DRPC_CALL ar_dsp_rpc.x
    This will generate ar_dsp_rpc_xdr.c ar_dsp_rpc_clnt.c ar_dsp_rpc_svr.c ar_dsp_rpc.h.
2. rpcgen -Ss -o server_func.c ar_dsp_rpc.x
    This will generate server_func.c, which is an example code of RPC APIs in server side, users can add their code inside those functions.
3. Merge server_func.c into ar_dsp_rpc_svr_func.c(a lot of user code in this .c file, so be careful).
