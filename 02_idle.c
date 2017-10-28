#include "learnuv.h"

void idle_cb(uv_idle_t* handle) {
  static int64_t count = -1;
  count++;
  if ((count % 10000) == 0) log_report(".");
  if (count >= 50000) uv_idle_stop(handle);
}

int main() {
  uv_idle_t idle_handle;
  

  /* 1. create the event loop */
  uv_loop_t* loop = malloc(sizeof(uv_loop_t));
  uv_loop_init(loop);
  
  /* 2. initialize an idle handler for the loop */

  int r = uv_idle_init(loop, &idle_handle);
  /* 3. start the idle handler with a function to call */
  int start = uv_idle_start( &idle_handle,  idle_cb);
  /* 4. start the event loop */
  uv_run(loop, UV_RUN_DEFAULT);
  uv_loop_close(loop);
  return 0;
}
