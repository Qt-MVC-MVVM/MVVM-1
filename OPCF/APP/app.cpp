#include "app.h"

app_opcf::app_opcf()
{
}

app_opcf::~app_opcf()
{
}

void app_opcf::run()
{
	model = std::make_shared<Model>();
	viewmodel = std::make_shared<ViewModel>();

	//将model与viewmodel绑定。
	viewmodel->SetModel(model);
	//_mainwindow.SetViewModel(viewmodel);

	_mainwindow.set_function(viewmodel->getFunction());
	//将mainwindow设置为viewmodel的信息接收者

	sp_opcf_command = std::make_shared<opcf_command>(this);

	_mainwindow.set_ptrCommand(std::static_pointer_cast<ICommandBase>(this->sp_opcf_command));
	_mainwindow.show();
}

MainWindow* app_opcf::getmainwindow()
{
	return &_mainwindow;
}
