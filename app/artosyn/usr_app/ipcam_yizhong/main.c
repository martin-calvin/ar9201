#include "ar_ipcam.h"
#include "ar_ipcam_type.h"
#include "ar_ipcam_gdbus_wrap.h"

int main(int argc, char *argv[])
{
   ar_ipcam_gdbus_obj_t* gdbus_obj = NULL;
   ipcam_obj_t *ipcam_obj = NULL;

   ipcam_obj = ipcam_init();
   if (!ipcam_obj) {
       printf("ipcam init error");
       return -1;
   }
   printf("create gdbus start");
   gdbus_obj = ar_ipcam_gdbus_create(ipcam_obj);
   if (!gdbus_obj) {
       printf("gdbus obj create error");
       return -1;
   }
   ar_ipcam_gdbus_run(gdbus_obj);
   ar_ipcam_gdbus_destroy(gdbus_obj);

   return 0;
}
