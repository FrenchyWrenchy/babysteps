#include "babystepsApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
babystepsApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

babystepsApp::babystepsApp(InputParameters parameters) : MooseApp(parameters)
{
  babystepsApp::registerAll(_factory, _action_factory, _syntax);
}

babystepsApp::~babystepsApp() {}

void
babystepsApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<babystepsApp>(f, af, s);
  Registry::registerObjectsTo(f, {"babystepsApp"});
  Registry::registerActionsTo(af, {"babystepsApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
babystepsApp::registerApps()
{
  registerApp(babystepsApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
babystepsApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  babystepsApp::registerAll(f, af, s);
}
extern "C" void
babystepsApp__registerApps()
{
  babystepsApp::registerApps();
}
