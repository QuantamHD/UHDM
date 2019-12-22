/*
 Do not modify, auto-generated by model_gen.tcl

 Copyright 2019 Alain Dargelas

 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at

 http://www.apache.org/licenses/LICENSE-2.0

 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

/*
 * File:   Serializer.cpp
 * Author:
 *
 * Created on December 14, 2019, 10:03 PM
 */

#include <vector>
#include <map>
#include "headers/uhdm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "UHDM.capnp.h"
#include <capnp/message.h>
#include <capnp/serialize-packed.h>
#include <iostream>


using namespace UHDM;

std::vector<uhdm_handle*> uhdm_handleFactory::objects_;

std::map<BaseClass*, unsigned long> allIds;

void setId(BaseClass* p, unsigned long id) {
  allIds.insert(std::make_pair(p, id));
}

static unsigned long incrId = 0;
unsigned long getId(BaseClass* p) {
  std::map<BaseClass*, unsigned long>::iterator itr = allIds.find(p);
  if (itr == allIds.end()) {
    unsigned long tmp = incrId;
    allIds.insert(std::make_pair(p, incrId));
    incrId++;
    return tmp;		  
  } else {
    return (*itr).second;
  }
}


std::vector<process*> processFactory::objects_;
std::vector<std::vector<process*>*> VectorOfprocessFactory::objects_;
std::vector<scope*> scopeFactory::objects_;
std::vector<std::vector<scope*>*> VectorOfscopeFactory::objects_;
std::vector<interface*> interfaceFactory::objects_;
std::vector<std::vector<interface*>*> VectorOfinterfaceFactory::objects_;
std::vector<interface_array*> interface_arrayFactory::objects_;
std::vector<std::vector<interface_array*>*> VectorOfinterface_arrayFactory::objects_;
std::vector<cont_assign*> cont_assignFactory::objects_;
std::vector<std::vector<cont_assign*>*> VectorOfcont_assignFactory::objects_;
std::vector<port*> portFactory::objects_;
std::vector<std::vector<port*>*> VectorOfportFactory::objects_;
std::vector<module_array*> module_arrayFactory::objects_;
std::vector<std::vector<module_array*>*> VectorOfmodule_arrayFactory::objects_;
std::vector<primitive*> primitiveFactory::objects_;
std::vector<std::vector<primitive*>*> VectorOfprimitiveFactory::objects_;
std::vector<primitive_array*> primitive_arrayFactory::objects_;
std::vector<std::vector<primitive_array*>*> VectorOfprimitive_arrayFactory::objects_;
std::vector<mod_path*> mod_pathFactory::objects_;
std::vector<std::vector<mod_path*>*> VectorOfmod_pathFactory::objects_;
std::vector<tchk*> tchkFactory::objects_;
std::vector<std::vector<tchk*>*> VectorOftchkFactory::objects_;
std::vector<def_param*> def_paramFactory::objects_;
std::vector<std::vector<def_param*>*> VectorOfdef_paramFactory::objects_;
std::vector<io_decl*> io_declFactory::objects_;
std::vector<std::vector<io_decl*>*> VectorOfio_declFactory::objects_;
std::vector<alias_stmt*> alias_stmtFactory::objects_;
std::vector<std::vector<alias_stmt*>*> VectorOfalias_stmtFactory::objects_;
std::vector<clocking_block*> clocking_blockFactory::objects_;
std::vector<std::vector<clocking_block*>*> VectorOfclocking_blockFactory::objects_;
std::vector<instance_array*> instance_arrayFactory::objects_;
std::vector<std::vector<instance_array*>*> VectorOfinstance_arrayFactory::objects_;
std::vector<module*> moduleFactory::objects_;
std::vector<std::vector<module*>*> VectorOfmoduleFactory::objects_;
std::vector<design*> designFactory::objects_;
std::vector<std::vector<design*>*> VectorOfdesignFactory::objects_;


void Serializer::save(std::string file) {
  int fileid = open(file.c_str(), O_CREAT | O_WRONLY , S_IRWXU);
  ::capnp::MallocMessageBuilder message;
  UhdmRoot::Builder cap_root = message.initRoot<UhdmRoot>();
  unsigned long index = 0;


  index = 0;
  for (auto obj : processFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : scopeFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : interfaceFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : interface_arrayFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : cont_assignFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : portFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : module_arrayFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : primitiveFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : primitive_arrayFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : mod_pathFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : tchkFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : def_paramFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : io_declFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : alias_stmtFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : clocking_blockFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : instance_arrayFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : moduleFactory::objects_) {
    setId(obj, index);
    index++;
  }
  index = 0;
  for (auto obj : designFactory::objects_) {
    setId(obj, index);
    index++;
  }
  
  ::capnp::List<Design>::Builder designs = cap_root.initDesigns(designFactory::objects_.size());
  index = 0;
  for (auto design : designFactory::objects_) {
    designs[index].setVpiName(design->get_vpiName());
    index++;
  }
  

 ::capnp::List<Module>::Builder Modules = cap_root.initFactoryModule(moduleFactory::objects_.size());
 index = 0;
 for (auto obj : moduleFactory::objects_) {
    Modules[index].setVpiName(obj->get_vpiName());
    Modules[index].setVpiTopModule(obj->get_vpiTopModule());
    Modules[index].setVpiDefDecayTime(obj->get_vpiDefDecayTime());

   index++;
 }
 ::capnp::List<Design>::Builder Designs = cap_root.initFactoryDesign(designFactory::objects_.size());
 index = 0;
 for (auto obj : designFactory::objects_) {
    Designs[index].setVpiName(obj->get_vpiName());

   index++;
 }
  
  writePackedMessageToFd(fileid, message);   
  close(fileid);
}

const std::vector<vpiHandle> Serializer::restore(std::string file) {
  std::vector<vpiHandle> designs;
  int fileid = open(file.c_str(), O_RDONLY);
  ::capnp::PackedFdMessageReader message(fileid);
  UhdmRoot::Reader cap_root = message.getRoot<UhdmRoot>();
  
  for (Design::Reader d : cap_root.getDesigns()) {
    design* uhdm_design = designFactory::make(); 
    uhdm_design->set_vpiName(d.getVpiName());
    vpiHandle designH = uhdm_handleFactory::make(uhdmdesign, uhdm_design);
    designs.push_back(designH);
  
     
  } 
  close(fileid); 
  return designs;
}

