#ifndef CALLBACK_H_
#define CALLBACK_H_

#include <psptypes.h>

int exit_callback(int arg1, int arg2, void *common);
int callback_thread(SceSize args, void *argp);
int setup_callbacks(void);

#endif /* CALLBACK_H_ */