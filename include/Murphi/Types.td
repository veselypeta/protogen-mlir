#ifndef MURPHI_TYPES
#define MURPHI_TYPES

class Murphi_Type<string name> : TypeDef<Murphi_Dialect, name> {}

def IntegerType : Type<CPred<"$_self.isa<mlir::IntegerType>()">, "Integer Type">;
def IntegerAttr: Attr<CPred<"$_self.isa<mlir::IntegerAttr>()">, "Integer Attribute">;

#endif //MURPHI_TYPES