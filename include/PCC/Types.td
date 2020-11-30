#ifndef PCC_Types
#define PCC_Types

class PCC_Type<string name> : TypeDef<PCC_Dialect, name> {}


def PCC_MsgType : Type<CPred<"$_self.isa<MsgType>()">, "PCC Msg Type">;
def PCC_NetType : Type<CPred<"$_self.isa<NetType>()">, "PCC Net Type">;
def PCC_DataType : Type<CPred<"$_self.isa<DataType>()">, "PCC Data Type">;

def TestType : PCC_Type<"Test"> {
}

def PCC_Types : AnyTypeOf<[PCC_MsgType]>;
#endif //PCC_Types