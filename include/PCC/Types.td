#ifndef PCC_Types
#define PCC_Types

class PCC_Type<string name> : TypeDef<PCC_Dialect, name> {}


def PCC_MsgType : Type<CPred<"$_self.is<MsgType>()">, "PCC Msg Type">;

def NetworkType : PCC_Type<"Network"> {
  let mnemonic = "network";
  let summary = "A Singleton Type to represent a Network";
  let description = [{
    This is a semanctic placeholder type
    that represents a network on which a cache
    can send messages.
  }];
  let printer = [{
    $_printer << "Network";
  }];
  let parser = [{
    // parse the less than
    if ($_parser.parseLess()){
        return Type();
    }
    if ($_parser.parseKeyword("Network")){
        return Type();
    }
    if ($_parser.parseGreater()){
        return Type();
    }
    return NetworkType::get(ctxt);
  }];
}


def PCC_Types : AnyTypeOf<[PCC_MsgType]>;
#endif //PCC_Types