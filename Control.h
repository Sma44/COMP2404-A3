#ifndef CONTROL_H
#define CONTROL_H

#include "View.h"
#include "School.h"
#include <string>

/// @brief control class to handle control flow between user and program
/// NOTE: added a helper function to simplify controlflow in launch function
class Control{
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
