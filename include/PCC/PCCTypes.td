#ifndef PCC_Types
#define PCC_Types

#include "PCC/Dialect.h"

// // All of the types will extend this class.
class PCC_Type<string name> : TypeDef<PCC_Dialect, name> {}

// An alternate int type.
def NetworkType : PCC_Type<"Network"> {
  let mnemonic = "network";

  let summary = "An integer type with special semantics";

  let description = [{
    An alternate integer type. This type differentiates itself from the
    standard integer type by not having a SignednessSemantics parameter, just
    a width.
  }];
}
#endif //PCC_Types