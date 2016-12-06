#include<stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include<time.h>

void Hello()
{

srand(time(NULL));
int r = rand() % 2;
printf("%d",r);

if(r==0){
    void *handle;
    double (*cosine)(double);
    char *error;

   handle = dlopen("/home/ss4/Documents/Ashwini_folder/DynamicLoading/Namaste.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

   dlerror();   


   *(void **) (&cosine) = dlsym(handle, "cos");

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

   printf("%f\n", (*cosine)(2.0));
    dlclose(handle);
    exit(EXIT_SUCCESS);
Hello();
}
else
{
printf("To be loaded for Pranam.so");
}
}
