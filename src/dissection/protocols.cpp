#include "muzzle/dissection.hpp"

muzzle::ProtocolFieldSpecs ethernet_specs{101,
                                          {{"dest_mac", 0, 6},
                                           {"src_mac", 6, 6},
                                           {"eth_type/length/vlantag", 12, 2},
                                           {"fcs", -4, 4}}};

muzzle::ProtocolFieldSpecs ipv4_specs{101,
                                      {
                                          {"version", 0, 4},
                                          {"header_length", 4, 4},
                                          {"DSCP/ECN", 8, 8},
                                          {"total_length", 16, 16},
                                          {"identification", 32, 16},
                                          {"flags & fragment offset", 48, 16},
                                          {"ttl", 64, 8},
                                          {"protocol", 72, 8},
                                          {"header_checksum", 80, 16},
                                          {"src_ip", 96, 32},
                                          {"dst_ip", 128, 32},
                                          {"options", 128, 320},
                                      }};

muzzle::ProtocolFieldSpecs arp_specs{101,
                                     {
                                         {"hardware_type", 0, 16},
                                         {"protocol_type", 16, 16},
                                         {"hardware_addr_len", 32, 8},
                                         {"protocol_addr_len", 40, 8},
                                         {"opcode", 48, 16},
                                         {"src_mac", 64, 48},
                                         {"src_ip", 112, 32},
                                         {"dst_mac", 144, 48},
                                         {"dst_ip", 192, 32},
                                     }};

muzzle::ProtocolFieldSpecs udp_specs{101,
                                     {
                                         {"src_port", 0, 16},
                                         {"dst_port", 16, 16},
                                         {"length", 32, 16},
                                         {"checksum", 48, 16},
                                     }};

muzzle::ProtocolFieldSpecs tpc_specs{101,
                                     {
                                         {"src_port", 0, 16},
                                         {"dst_port", 16, 16},
                                         {"seq", 32, 32},
                                         {"ack", 64, 32},
                                         {"data_offset", 96, 4},
                                         {"reserved_and_flags", 96, 12},
                                         {"window_size", 108, 16},
                                         {"checksum", 124, 16},
                                         {"urgent_pointer", 140, 16},
                                         {"options", 156, 320},
                                     }};
