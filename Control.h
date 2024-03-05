#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "School.h"
#include <string>


class Control
{
  public:
    Control();
    ~Control();
    void launch();

  private:
    View view;
    School* school;
    void initStudents(School*);
    void initCourses(School*);
    void stuControlFlow();

};

#endif
