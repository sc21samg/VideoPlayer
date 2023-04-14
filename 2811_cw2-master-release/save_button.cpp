#include "save_button.h"
#include <QHBoxLayout>


save_button::save_button(ThePlayer* player)
{
  p = player;
  createWidget();
  arrangeWidget();
  makeConnections();
}

//checking if save button is clicked or not
void save_button::buttonClicked(bool checked)
{
  if(checked)
  {
    QDialog::close();
  }
  else
  {
    QDialog::show();
  }
}

//widget creation for save
void save_button::createWidget()
{
   dialog =  new QDialogButtonBox(Qt::Horizontal);
   Yes = new QPushButton("Save");
   No = new QPushButton("Don't Save");
   label = new QLabel("Do you want to save file ?");
}

//arranging widget into dialog box horizontally
void save_button::arrangeWidget()
{
    QVBoxLayout* v = new QVBoxLayout();
    v->addWidget(label);
    dialog->addButton(Yes, QDialogButtonBox::ActionRole);
    dialog->addButton(No, QDialogButtonBox::ActionRole);

    v->addWidget(dialog);
    v->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(v);
}

void save_button::makeConnections()
{
  //connecting "Don't save" button to close() when user do not need to save file
  connect(No, SIGNAL(clicked(bool)), this, SLOT(close()));
  //connecting "save" button to save video when user need to save file in "playlist"
  connect(Yes, SIGNAL(clicked(bool)), p, SLOT(save_current_video()));
  //after completion of saving file we need to close dialog box
  connect(Yes, SIGNAL(clicked(bool)), this, SLOT(close()));

}
