#include "muzzle/dissection.hpp"
#include <memory>

using namespace std;
using namespace muzzle;

Protocol Dissector::dissect(vector<char> &payload, int linktype) { return {}; }

void Dissector::register_protocol_specs(ProtocolFieldSpecs specs, int opcode) {
  this->opcode_to_specs.insert_or_assign(opcode, std::move(specs));
}

void Dissector::register_protocol_dependency(ProtocolDependency dependency,
                                             int dependency_opcode) {
  this->opcode_to_dependencies[dependency_opcode].push_back(
      std::move(dependency));
}
