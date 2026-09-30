#ifndef DISSECT_HPP
#define DISSECT_HPP

#include <any>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
using ProtocolMetadata = unordered_map<string, any>;

class Protocol {
  int opcode;
  string fullname;
  string shortname;
  string filtername;
  unique_ptr<ProtocolMetadata> metadata;
  unique_ptr<vector<char>> payload;
  unique_ptr<Protocol> next;
};

// This may need to changed to handle more complex protocols
class ProtocolFieldSpecs {
  int opcode;
  int len;
  int offset;
  int datatype;
};

class ProtocolDependency {
  int opcode;
  int precedance;
  vector<unique_ptr<pair<string, any>>> dependencies;
};

class Dissector {
  map<int, unique_ptr<ProtocolFieldSpecs>> opcode_to_specs;
  map<int, vector<unique_ptr<ProtocolDependency *>>> opcode_to_dependencies;

public:
  Protocol dissect(vector<char> &payload, int linktype);
  void register_protocol_specs(ProtocolFieldSpecs *specs, int opcode);
  void register_protocol_dependency(ProtocolDependency *dependency,
                                    int dependency_opcode);

private:
  int get_next_protocol_opcode(Protocol protocol);
};

#endif
