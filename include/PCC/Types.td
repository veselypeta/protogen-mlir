#ifndef PCC_Types
#define PCC_Types

class PCC_Type<string name> : TypeDef<PCC_Dialect, name> {}


def PCC_MsgType : Type<CPred<"$_self.isa<MsgType>()">, "PCC Msg Type">;

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

def DataType : PCC_Type<"Data"> {
  let mnemonic = "data";
  let summary = "Singleton Type to represent Cache Line Data";
  let description = [{
    This is a semantic plaeholder type that represents
    a cache line data block.
  }];
  let printer = [{
    $_printer << "Data";
  }];
  let parser = [{
    return Type();
  }];
}


def PCC_Types : AnyTypeOf<[PCC_MsgType]>;
#endif //PCC_Types