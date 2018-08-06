#define CATCH_CONFIG_MAIN
#include <Catch2/catch.hpp>
#include <Vytrix.hpp>

TEST_CASE("Vytrix matrix tests", "[Vytrix]"){
    SECTION("Empty Matrix"){
        Vytrix<float> vytrix;
        REQUIRE(vytrix[0][0] == 0.0f);
        REQUIRE(vytrix[0][1] == 0.0f);
        REQUIRE(vytrix[0][2] == 0.0f);
        REQUIRE(vytrix[0][3] == 0.0f);
        REQUIRE(vytrix[1][0] == 0.0f);
        REQUIRE(vytrix[1][1] == 0.0f);
        REQUIRE(vytrix[1][2] == 0.0f);
        REQUIRE(vytrix[1][3] == 0.0f);
        REQUIRE(vytrix[2][0] == 0.0f);
        REQUIRE(vytrix[2][1] == 0.0f);
        REQUIRE(vytrix[2][2] == 0.0f);
        REQUIRE(vytrix[2][3] == 0.0f);
        REQUIRE(vytrix[3][0] == 0.0f);
        REQUIRE(vytrix[3][1] == 0.0f);
        REQUIRE(vytrix[3][2] == 0.0f);
        REQUIRE(vytrix[3][3] == 0.0f);
    }
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
        Vypoint<float> lh_vypoint({1.0f,2.0f,3.0f,4.0f});
        Vytrix<float> rh_vytrix({{16.0f,15.0f,14.0f,13.0f},{12.0f,11.0f,10.0f,9.0f},{8.0f,7.0f,6.0f,5.0f},{4.0f,3.0f,2.0f,1.0f}});
        Vypoint<float> result_vypoint = lh_vypoint*rh_vytrix;
        REQUIRE(result_vypoint[0] == 80.0f);
        REQUIRE(result_vypoint[1] == 70.0f);
        REQUIRE(result_vypoint[2] == 60.0f);
        REQUIRE(result_vypoint[3] == 50.0f);
    }
    SECTION("Vector normalization"){
        Vypoint<float> init_vector({1.0f, 1.0f, 1.0f, 0.0f});
        init_vector.normalize_vector();
        REQUIRE(init_vector[0] == Approx(.57735f));
        REQUIRE(init_vector[1] == Approx(.57735f));
        REQUIRE(init_vector[2] == Approx(.57735f));
        Vypoint<float> init_vector_zero({0.0f,0.0f,0.0f,0.0f});
        init_vector_zero.normalize_vector();
        REQUIRE(init_vector_zero[0] == 0.0f);
        REQUIRE(init_vector_zero[1] == 0.0f);
        REQUIRE(init_vector_zero[2] == 0.0f);
        Vypoint<float> init_vector_random({3.0f, 2.0f, -1.0f, 1.0f});
        init_vector_random.normalize_vector();
        REQUIRE(init_vector_random[0] == Approx(.801784));
        REQUIRE(init_vector_random[1] == Approx(.534522));
        REQUIRE(init_vector_random[2] == Approx(-.267261));
    }
    SECTION("Vector Dot Product"){
        Vypoint<float> vector_1_1({3000.0f, 10.0f, 125.35f, 0.0f});
        Vypoint<float> vector_1_2({0.0f, 0.0f, 0.0f, 0.0f});
        float dot_prod_1_1 = vector_1_1.dot_product(vector_1_2);
        REQUIRE(dot_prod_1_1 == 0.0f);
        Vypoint<float> vector_1_3({1.0f, 1.0f, 1.0f, 0.0f});
        Vypoint<float> vector_1_4({1.0f, 1.0f, 1.0f, 0.0f});
        float dot_prod_1_2 = vector_1_3.dot_product(vector_1_4);
        REQUIRE(dot_prod_1_2 == 3.0f);
        Vypoint<float> vector_1({10.0f, 20.0f, 30.0f, 1.0f});
        Vypoint<float> vector_2({20.0f, 45.0f, 75.0f, 1.0f});
        float dot_prod_1 = vector_1.dot_product(vector_2);
        REQUIRE(dot_prod_1 == 3350.0f);
    }
    SECTION("Vector Cross Product"){
        Vypoint<float> vector_1({1.0f,2.0f,3.0f,1.0f});
        Vypoint<float> vector_2({1.0f,5.0f,7.0f,1.0f});
        Vypoint<float> cross_product = vector_1.x_product(vector_2);
        REQUIRE(cross_product[0] == -1.0f);
        REQUIRE(cross_product[1] == -4.0f);
        REQUIRE(cross_product[2] == 3.0f);
        REQUIRE(cross_product[3] == 1.0f);
    }
    SECTION("Vector arithmetic operations"){
        Vypoint<float> vector_1({1.0f,1.0f,1.0f, 1.0f});
        Vypoint<float> vector_2({10.0f,11.0f,12.0f,1.0f});
        vector_1.add_vector(vector_2);
        REQUIRE(vector_1[0] == 11.0f);
        REQUIRE(vector_1[1] == 12.0f);
        REQUIRE(vector_1[2] == 13.0f);
        REQUIRE(vector_1[3] == 1.0f);
        Vypoint<float> vector_3({5.0f,6.0f,7.0f,1.0f});
        vector_1.subtract_vector(vector_3);
        REQUIRE(vector_1[0] == 6.0f);
        REQUIRE(vector_1[1] == 6.0f);
        REQUIRE(vector_1[2] == 6.0f);
        REQUIRE(vector_1[3] == 1.0f);
        vector_1.multiply_scalar(2.0f);
        REQUIRE(vector_1[0] == 12.0f);
        REQUIRE(vector_1[1] == 12.0f);
        REQUIRE(vector_1[2] == 12.0f);
        REQUIRE(vector_1[3] == 1.0f);
    }
}

TEST_CASE("Rotation operations", "[Vytrix]"){
    SECTION("Degrees to Radians"){
        REQUIRE(Vytrix<float>::deg_to_rad(1.0f) == Approx(0.0174533f));
        REQUIRE(Vytrix<float>::deg_to_rad(180.0f) == Approx(3.14159));
        REQUIRE(Vytrix<float>::deg_to_rad(560.0f) == Approx(9.77384));
    }
    SECTION("Rotation X Axis Matrix"){
        float rad = Vytrix<float>::deg_to_rad(15.0f);
        Vytrix<float> vytrix = Vytrix<float>::retrieve_x_rotation(rad);
        REQUIRE(vytrix[0][0] == 1.0f);
        REQUIRE(vytrix[0][1] == 0.0f);
        REQUIRE(vytrix[0][2] == 0.0f);
        REQUIRE(vytrix[0][3] == 0.0f);
        REQUIRE(vytrix[1][0] == 0.0f);
        REQUIRE(vytrix[1][1] == Approx(0.96592592665));
        REQUIRE(vytrix[1][2] == Approx(0.25881867051));
        REQUIRE(vytrix[1][3] == 0.0f);
        REQUIRE(vytrix[2][0] == 0.0f);
        REQUIRE(vytrix[2][1] == Approx(-0.25881867051));
        REQUIRE(vytrix[2][2] == Approx(0.96592592665));
        REQUIRE(vytrix[2][3] == 0.0f);
        REQUIRE(vytrix[3][0] == 0.0f);
        REQUIRE(vytrix[3][1] == 0.0f);
        REQUIRE(vytrix[3][2] == 0.0f);
        REQUIRE(vytrix[3][3] == 1.0f);
    }
    SECTION("Rotation Y Axis Matrix"){
        float rad = Vytrix<float>::deg_to_rad(15.0f);
        Vytrix<float> vytrix = Vytrix<float>::retrieve_y_rotation(rad);
        REQUIRE(vytrix[0][0] == Approx(0.96592592665));
        REQUIRE(vytrix[0][1] == 0.0f);
        REQUIRE(vytrix[0][2] == Approx(-0.25881867051));
        REQUIRE(vytrix[0][3] == 0.0f);
        REQUIRE(vytrix[1][0] == 0.0f);
        REQUIRE(vytrix[1][1] == 1.0f);
        REQUIRE(vytrix[1][2] == 0.0f);
        REQUIRE(vytrix[1][3] == 0.0f);
        REQUIRE(vytrix[2][0] == Approx(0.25881867051));
        REQUIRE(vytrix[2][1] == 0.0f);
        REQUIRE(vytrix[2][2] == Approx(0.96592592665));
        REQUIRE(vytrix[2][3] == 0.0f);
        REQUIRE(vytrix[3][0] == 0.0f);
        REQUIRE(vytrix[3][1] == 0.0f);
        REQUIRE(vytrix[3][2] == 0.0f);
        REQUIRE(vytrix[3][3] == 1.0f);
    }
    SECTION("Rotation Z Axis Matrix"){
        float rad = Vytrix<float>::deg_to_rad(15.0f);
        Vytrix<float> vytrix = Vytrix<float>::retrieve_z_rotation(rad);
        REQUIRE(vytrix[0][0] == Approx(0.96592592665));
        REQUIRE(vytrix[0][1] == Approx(0.25881867051));
        REQUIRE(vytrix[0][2] == 0.0f);
        REQUIRE(vytrix[0][3] == 0.0f);
        REQUIRE(vytrix[1][0] == Approx(-0.25881867051));
        REQUIRE(vytrix[1][1] == Approx(0.96592592665));
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
}

