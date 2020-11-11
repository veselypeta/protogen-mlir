// RUN: murphi-opt %s | murphi-opt | FileCheck %s

module {

    func @test(){
                
        "murphi.constant_decl"() ({
            // CHECK: %0 = "murphi.constant"() {id = "nrCaches", value = 32 : i32} : () -> i32
            %0 = "murphi.constant"() {value = 32: i32, id = "nrCaches"} : () -> i32

            //CHECK: %1 = "murphi.constant"() {id = "myFloat", value = {{.*}} : f64} : () -> f64
            %1 = "murphi.constant"() {value = 12.6: f64, id = "myFloat"}: () -> f64

            // CHECK: %2 = "pcc.constant"() {id = "pccNrCaches", value = 44 : i32} : () -> i32
            %2 = "pcc.constant"() {value = 44 : i32, id = "pccNrCaches"} : () -> i32

            //CHECK: "murphi.return"() : () -> ()
            "murphi.return"(): () -> ()

        }): () -> ()

        return
    }
}