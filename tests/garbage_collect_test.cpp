// -*- mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; -*-

#include <iostream>

#include "gtest/gtest.h"
#include "uhdm/uhdm.h"
#include "uhdm/vpi_visitor.h"

using namespace UHDM;

static std::vector<vpiHandle> build_designs(Serializer* s) {
  std::vector<vpiHandle> designs;
  // Design building
  design* d = s->MakeDesign();
  d->VpiName("design1");

  // Module
  module* m1 = s->MakeModule();
  m1->VpiTopModule(true);
  m1->VpiDefName("M1");
  m1->VpiParent(d);

  // Module
  module* m2 = s->MakeModule();
  m2->VpiDefName("M2");
  m2->VpiName("u1");

  VectorOfmodule* v1 = s->MakeModuleVec();
  v1->push_back(m1);
  d->TopModules(v1);

  vpiHandle dh = s->MakeUhdmHandle(uhdmdesign, d);
  designs.push_back(dh);

  return designs;
}

TEST(GarbageCollectTest, NoLeakExpectation) {
  Serializer serializer;
  const std::vector<vpiHandle>& designs = build_designs(&serializer);
  const std::string before = visit_designs(designs);

  const std::string filename = testing::TempDir() + "/gc_test.uhdm";
  serializer.Save(filename);
  for (vpiHandle design : designs) {
    vpi_release_handle(design);
  }

  const std::vector<vpiHandle>& restoredDesigns = serializer.Restore(filename);
  const std::string restored = visit_designs(restoredDesigns);

  std::string decompiled;
  for (auto objIndexPair : serializer.AllObjects()) {
    if (objIndexPair.first) {
      decompiled += "OBJECT:\n";
      decompiled += decompile((any*)objIndexPair.first);
    }
  }
  // TODO: decompiled needs to be compared with something, otherwise this
  // test is not useful. Nobody looks a the logs.
  std::cerr << decompiled << "\n";

  for (vpiHandle design : restoredDesigns) {
    vpi_release_handle(design);
  }
  serializer.Purge();
}
