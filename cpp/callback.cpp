#include<iostream>
using namespace std;

/* ====================================== basic callback synchronous*/
/* void principalFn(char ch[],int (*ptr)(int)){ */
/*     int a=3; */
/*     int b=4; */
/*     int op = (*ptr)(b); */
/*     cout<<"OP:"<<op; */
/* } */

/* int cb(int num){ */
/*     cout<<"Callback called"; */
/*     return num+5; */
/* } */
/* int main(){ */
/*     cout<<"Just working"; */
/*     char ch[] = "fine"; */
/*     /1* int (*ptr)(int) =&cb; *1/ */
/*     principalFn(ch,cb); */
/*     return 0; */
/* } */

/* ====================================== small modification*/
/* int principalFn(char ch[], int (*ptr)(int)) */
/* { */

/*         int id1 = 1; */
/*         int id2 = 2; */
/*         int idr = (*ptr)(id2); */

/*         cout<<"principal function: "<< */
/*           id1<<' '<<ch<<' '<<idr<<'\n'; */

/*         return id1; */
/* } */
/* int cb(int iden) */
/* { */
/*         cout<<"callback function"<<'\n'; */
/*         return iden; */
/* } */
/* int main() */
/* { */
/*    int (*ptr)(int) = &cb; */
/*    char cha[] = "and"; */
/*    principalFn(cha, ptr); */

/*    return 0; */
/* } */
/* ====================================== callback which is asynchronous*/
char *output;

void cb(char out[])
    {

        output = out;

    }

void principalFn(char input[], void (*ptr)(char[50]))
    {

        (*ptr)(input);

        cout<<"principal function"<<'\n';
    }

void fn()
    {
        cout<<"seen"<<'\n';
    }

int main()
{
    char input[] = "callback function";

    void (*ptr)(char[]) = &cb;

    principalFn(input, cb);

    fn();

    cout<<output<<'\n';

   return 0;
}
