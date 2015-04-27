#include <FL\Fl.H>
#include <FL\Fl_Window.H>
#include <FL\Fl_Button.H>
#include <FL\Fl_Input.H>
#include <FL\Fl_Output.H>
#include <iostream>



class MyMainWindow:public Fl_Window{
	Fl_Button *_btn1;
	Fl_Input *_input1;
	Fl_Output *_output1;
	
		
		static void MyCallback(Fl_Widget* w,void*para){
		
		//std::cout<<"Hello "<<std::endl;
		//std::cout<<"para=  "<<( MyMainWindow*)para<<std::endl;
		//std::cout<<"string input=  "<<(( MyMainWindow*)para)->_input1->value()<<std::endl;
			((MyMainWindow*)para)->_input1->label;
			((MyMainWindow*)para)->_output1->value->_input1.value();
			((MyMainWindow*)para)->_input1->value(""); //clear again

		if (w->color() == 0xFFFFFF00) {
			w->color(0xFF000000); //toggle
		}
			else {
		w->color(0xFFFFFF00);//toggle
		}
}
		 MyMainWindow(int w,int h,const char* caption):Fl_Window(w,h,caption){
		_btn1=new Fl_Button(130,200,100,25,"Click me!");
		_btn1->color(0xFFA81200);
		_input1=new Fl_Input(90, 10, 180, 20,"Output : ");
		_output1=new Fl_Output(90, 40, 180, 20, "Output : ");
		_input1->callback((Fl_Callback*)MyCallback, (void *)"Enter next:");
		_input1->when(FL_WHEN_RELEASE |FL_WHEN_ENTER_KEY);
		_btn1->callback(MyCallback,this);


	show();
	}
	static MyMainWindow *_singleton;
public:
	
	static MyMainWindow *getSingleton(){
		if(_singleton==0)
			_singleton=new MyMainWindow(400,400,"Main window");
			return _singleton;
	}
	
	
	void Draw(double point_x,double point_y,unsigned color=0);
	void Draw(double point1_x,double point1_y,double point2_x,double point2_y);
	void Draw(double point_x,double point_y,double radius);
	void WriteError(unsigned ErrorKey);
};
MyMainWindow* MyMainWindow::_singleton=0;



int main(int argc,char *argv[]){
	 MyMainWindow *window1= MyMainWindow::getSingleton();
	window1->color(FL_WHITE);
	window1->show();
	/*MyWindow  *button=new MyWindow (10,10,100,25,"Press");
	
Fl_Window *window=new Fl_Window(300,180);
Fl_Button *button=new Fl_Button(10,10,100,25,"Press");
Fl_Input *input=new Fl_Input(10,40,100,25);
std::cout<<"Fl_Input created at "<<input<<std::endl;
button->callback(MyCallback,input);
*/
//window->show(argc,argv);

return Fl::run();

}