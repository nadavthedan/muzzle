#ifndef DISSECT_HPP
#define DISSECT_HPP

#include <any>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
namespace muzzle {

using ProtocolMetadata = unordered_map<string, any>;

class Protocol {
public:
  int opcode;
  string fullname;
  string shortname;
  string filtername;
  ProtocolMetadata metadata;
  vector<char> payload;
  unique_ptr<Protocol> next;
};

// This may need to changed to handle more complex protocols
class ProtocolFieldSpec {
public:
  string field_name;
  int offset;
  int len;
};

class ProtocolFieldSpecs {
public:
  int opcode;
  vector<ProtocolFieldSpec> specs;
};

class ProtocolDependency {
public:
  int opcode;
  int precedance;
  vector<pair<string, any>> dependencies;
};

class Dissector {
  map<int, ProtocolFieldSpecs> opcode_to_specs;
  map<int, vector<ProtocolDependency>> opcode_to_dependencies;

public:
  Protocol dissect(vector<char> &payload, int linktype);
  void register_protocol_specs(ProtocolFieldSpecs specs, int opcode);
  void register_protocol_dependency(ProtocolDependency dependency,
                                    int dependency_opcode);

private:
  int get_next_protocol_opcode(Protocol protocol);
};

} // namespace muzzle

#endif
