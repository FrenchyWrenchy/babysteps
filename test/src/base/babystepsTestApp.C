//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "babystepsTestApp.h"
#include "babystepsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
babystepsTestApp::validParams()
{
  InputParameters params = babystepsApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

babystepsTestApp::babystepsTestApp(InputParameters parameters) : MooseApp(parameters)
{
  babystepsTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

babystepsTestApp::~babystepsTestApp() {}

void
babystepsTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  babystepsApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"babystepsTestApp"});
    Registry::registerActionsTo(af, {"babystepsTestApp"});
  }
}

void
babystepsTestApp::registerApps()
{
  registerApp(babystepsApp);
  registerApp(babystepsTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
babystepsTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babystepsTestApp::registerAll(f, af, s);
}
extern "C" void
babystepsTestApp__registerApps()
{
  babystepsTestApp::registerApps();
}
