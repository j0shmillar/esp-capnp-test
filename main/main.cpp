#include "capnp/serialize-packed.h"
#include "schema.capnp.h"
#include <iostream>

extern "C" void app_main() {
  capnp::MallocMessageBuilder message;
  Message::Builder msg = message.initRoot<Message>();
  msg.setContent("Hello ESP32");
  msg.setId(123);

  // Serialize to buffer
  kj::VectorOutputStream output_stream;
  capnp::writePackedMessage(output_stream, message);

  // Access serialized data
  auto data = output_stream.getArray();
  printf("Serialized size: %zu\n", data.size());
}
