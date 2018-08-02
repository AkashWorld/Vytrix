#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>
#include "Vytrix.hpp"

TEST_CASE("Vytrix matrix tests", "[Vytrix]"){
    SECTION("Identity Matrix"){
        Vytrix<float> vytrix(1);
        REQUIRE(vytrix[0][0] == 1.0f);
        REQUIRE(vytrix[0][1] == 0.0f);
        REQUIRE(vytrix[0][2] == 0.0f);
        REQUIRE(vytrix[0][3] == 0.0f);
        REQUIRE(vytrix[1][0] == 0.0f);
        REQUIRE(vytrix[1][1] == 1.0f);
        REQUIRE(vytrix[1][2] == 0.0f);
        REQUIRE(vytrix[1][3] == 0.0f);
        REQUIRE(vytrix[2][0] == 0.0f);
        REQUIRE(vytrix[2][1] == 0.0f);
        REQUIRE(vytrix[2][2] == 1.0f);
        REQUIRE(vytrix[2][3] == 0.0f);
        REQUIRE(vytrix[3][0] == 0.0f);
        REQUIRE(vytrix[3][1] == 0.0f);
        REQUIRE(vytrix[3][2] == 0.0f);
        REQUIRE(vytrix[3][3] == 1.0f);
    }
    SECTION("Initializing matrix"){
        float new_input_matrix[4][4] = {{5.0f, 0.0f, -2.0f, 1.0f},{5.0f, 0.0f, -2.0f, 1.0f},{5.0f, 0.0f, -2.0f, 1.0f},{5.0f, 0.0f, -2.0f, 1.0f}};
        Vytrix<float> vytrix(new_input_matrix);
        REQUIRE(vytrix[0][0] == 5.0f);
        REQUIRE(vytrix[0][1] == 0.0f);
        REQUIRE(vytrix[0][2] == -2.0f);
        REQUIRE(vytrix[0][3] == 1.0f);
        REQUIRE(vytrix[1][0] == 5.0f);
        REQUIRE(vytrix[1][1] == 0.0f);
        REQUIRE(vytrix[1][2] == -2.0f);
        REQUIRE(vytrix[1][3] == 1.0f);    
        REQUIRE(vytrix[2][0] == 5.0f);
        REQUIRE(vytrix[2][1] == 0.0f);
        REQUIRE(vytrix[2][2] == -2.0f);
        REQUIRE(vytrix[2][3] == 1.0f);    
        REQUIRE(vytrix[3][0] == 5.0f);
        REQUIRE(vytrix[3][1] == 0.0f);
        REQUIRE(vytrix[3][2] == -2.0f);
        REQUIRE(vytrix[3][3] == 1.0f);
    }
    SECTION("Initializing matrix by directly inputting 2-D Array"){
        Vytrix<float> vytrix({{5.0f, 0.0f, -2.0f, 1.0f},{5.0f, 0.0f, -2.0f, 1.0f},{5.0f, 0.0f, -2.0f, 1.0f},{5.0f, 0.0f, -2.0f, 1.0f}});
        REQUIRE(vytrix[0][0] == 5.0f);
        REQUIRE(vytrix[0][1] == 0.0f);
        REQUIRE(vytrix[0][2] == -2.0f);
        REQUIRE(vytrix[0][3] == 1.0f);
        REQUIRE(vytrix[1][0] == 5.0f);
        REQUIRE(vytrix[1][1] == 0.0f);
        REQUIRE(vytrix[1][2] == -2.0f);
        REQUIRE(vytrix[1][3] == 1.0f);    
        REQUIRE(vytrix[2][0] == 5.0f);
        REQUIRE(vytrix[2][1] == 0.0f);
        REQUIRE(vytrix[2][2] == -2.0f);
        REQUIRE(vytrix[2][3] == 1.0f);    
        REQUIRE(vytrix[3][0] == 5.0f);
        REQUIRE(vytrix[3][1] == 0.0f);
        REQUIRE(vytrix[3][2] == -2.0f);
        REQUIRE(vytrix[3][3] == 1.0f);
    }
}

TEST_CASE("Matrix operations with Vytrix", "[Assignment]"){
    SECTION("Matrix Multiplication with Vytrix"){
        Vytrix<float> lh_matrix({{1.0f,2.0f,3.0f,4.0f},{5.0f,6.0f,7.0f,8.0f},{9.0f,10.0f,11.0f,12.0f},{13.0f,14.0f,15.0f,16.0f}});
        Vytrix<float> rh_matrix({{16.0f,15.0f,14.0f,13.0f},{12.0f,11.0f,10.0f,9.0f},{8.0f,7.0f,6.0f,5.0f},{4.0f,3.0f,2.0f,1.0f}});
        Vytrix<float> product = lh_matrix*rh_matrix;
        REQUIRE(product[0][0] == 80.0f);
        REQUIRE(product[0][1] == 70.0f);
        REQUIRE(product[0][2] == 60.0f);
        REQUIRE(product[0][3] == 50.0f);
        REQUIRE(product[1][0] == 240.0f);
        REQUIRE(product[1][1] == 214.0f);
        REQUIRE(product[1][2] == 188.0f);
        REQUIRE(product[1][3] == 162.0f);    
        REQUIRE(product[2][0] == 400.0f);
        REQUIRE(product[2][1] == 358.0f);
        REQUIRE(product[2][2] == 316.0f);
        REQUIRE(product[2][3] == 274.0f);    
        REQUIRE(product[3][0] == 560.0f);
        REQUIRE(product[3][1] == 502.0f);
        REQUIRE(product[3][2] == 444.0f);
        REQUIRE(product[3][3] == 386.0f);
    }
}

TEST_CASE("Vector Initialization", "[Vector]"){
    SECTION("Vector initialization test"){
        Vypoint<float> init_vypoint;
        REQUIRE(init_vypoint[0] == 0.0f);
        REQUIRE(init_vypoint[1] == 0.0f);
        REQUIRE(init_vypoint[2] == 0.0f);
        REQUIRE(init_vypoint[3] == 0.0f);
    }
    SECTION("Vector initialization with single parameter"){
        Vypoint<float> init_vypoint(41.0f);
        REQUIRE(init_vypoint[0] == 41.0f);
        REQUIRE(init_vypoint[1] == 41.0f);
        REQUIRE(init_vypoint[2] == 41.0f);
        REQUIRE(init_vypoint[3] == 41.0f);
    }
    SECTION("Vector initialization with input array"){
        Vypoint<float> init_vypoint({11.0f, 21.0f, 31.0f, 41.0f});
        REQUIRE(init_vypoint[0] == 11.0f);
        REQUIRE(init_vypoint[1] == 21.0f);
        REQUIRE(init_vypoint[2] == 31.0f);
        REQUIRE(init_vypoint[3] == 41.0f);
    }
}

TEST_CASE("Vector Operations", "[Vector]"){
    SECTION("Vector and Matrix multiplication"){
        Vypoint<float> lh_vypoint({1.0f,2.0f,3.0f,4.0f}); lh_vypoint.print();
        Vytrix<float> rh_vytrix({{16.0f,15.0f,14.0f,13.0f},{12.0f,11.0f,10.0f,9.0f},{8.0f,7.0f,6.0f,5.0f},{4.0f,3.0f,2.0f,1.0f}});
        rh_vytrix.print();
        Vypoint<float> result_vypoint = lh_vypoint*rh_vytrix;
        result_vypoint.print();
        REQUIRE(result_vypoint[0] == 80.0f);
        REQUIRE(result_vypoint[1] == 70.0f);
        REQUIRE(result_vypoint[2] == 60.0f);
        REQUIRE(result_vypoint[3] == 50.0f);
    }
}
