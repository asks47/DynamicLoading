#include <stdlib.h>
    #include <stdio.h>
    #include <dlfcn.h>
#include<time.h>


    int main(int argc, char **argv) {
        void *handle;
        //double (*cosine)(double);
        char *error;
        char (*cosine)(char);
     
   srand(time(NULL));
int r = rand() % 2;
printf("%d-",r);

if(r==0){

        handle = dlopen ("/home/ss4/Documents/Ashwini_folder/DynamicLoading/Namaste.so", RTLD_LAZY);
        if (!handle) {
            fputs (dlerror(), stderr);
            exit(1);
        }

        cosine = dlsym(handle, "Hello");
        if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }

        printf ("%c\n", (*cosine)(2.0));
        dlclose(handle);
    }

else
{
handle = dlopen ("/home/ss4/Documents/Ashwini_folder/DynamicLoading/Pranam.so", RTLD_LAZY);
        if (!handle) {
            fputs (dlerror(), stderr);
            exit(1);
        }

        cosine = dlsym(handle, "Hello");
        if ((error = dlerror()) != NULL)  {
            fputs(error, stderr);
            exit(1);
        }

        printf ("%c\n", (*cosine)(2.0));
        dlclose(handle);

}
}

