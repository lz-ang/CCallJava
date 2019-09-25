#include <jni.h>

//env是个二级指针，JNIEnvb本来就是一个指针
JNIEXPORT void JNICALL Java_com_example_ccalljava_MainActivity_helloC//函数名：Java包名+类名+方法名
  (JNIEnv* env, jobject obj)//这两个参数必须要写，JNIEvn* 是java运行环境的地址，可以理解为Java虚拟机地址；jobject Java中调用本地方的对象
{
	//jclass      (*FindClass)(JNIEnv*, const char*); jni.h中定义的函数指针
    jclass class = (*env)->FindClass(env,"com/example/ccalljava/MainActivity"); //是不是和MainActivity.class.forName(classNmae);类似

    //jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);//第三个参数是要反射的方法名;最后一个参数char*是要反射调用的方法的签名
    jmethodID methodID = (*env)->GetMethodID(env,class,"show","(Ljava/lang/String;)V");

    //   void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...); 因为show返回值是void类型的所以这里调用CallVoidMethod()函数
    (*env)->CallVoidMethod(env,obj,methodID,(*env)->NewStringUTF(env,"C调用Java方法显示的弹窗"));//jstring     (*NewStringUTF)(JNIEnv*, const char*);
    //(*env)->CallVoidMethod(env,obj,methodID,(*env)->NewStringUTF);
}
