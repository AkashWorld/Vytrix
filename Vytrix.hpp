#pragma once
#include <cmath>
#include <iostream>
#define SWAP_ROWS(matrix, r1, r2) type placeholder_row[4];\
    memcpy(placeholder_row, matrix[r1], sizeof(type)*4);\
    memcpy(matrix[r1], matrix[r2], sizeof(type)*4);\
    memcpy(matrix[r2], placeholder_row, sizeof(type)*4);\
//TODO: Unroll loop
template <typename type>
class Vytrix{
    public:
    type matrix[4][4] = {};
    Vytrix(){

    }
    Vytrix(const type (&input)[4][4]){
        for(size_t i = 0; i < 4; ++i){
            for(size_t j = 0; j < 4; ++j){
                matrix[i][j] = input[i][j];
            }
        }
    }
    Vytrix(const uint32_t flag){
        if(flag == 1){
            matrix[0][0] = 1.0f; matrix[1][1] = 1.0f; matrix[2][2] = 1.0f; matrix[3][3] = 1.0f;
        }
    }
    type* operator [] (uint32_t i) {return matrix[i];}
    Vytrix operator * (Vytrix& rh_matrix){
        Vytrix product_vytrix;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                 product_vytrix[i][j] = matrix[i][0]*rh_matrix[0][j] +
                                        matrix[i][1]*rh_matrix[1][j] +
                                        matrix[i][2]*rh_matrix[2][j] +
                                        matrix[i][3]*rh_matrix[3][j];
            }
        }
        return product_vytrix;
    }
    Vytrix operator * (const Vytrix& rh_matrix) const {
        Vytrix product_vytrix;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                 product_vytrix[i][j] = matrix[i][0]*rh_matrix[0][j] +
                                        matrix[i][1]*rh_matrix[1][j] +
                                        matrix[i][2]*rh_matrix[2][j] +
                                        matrix[i][3]*rh_matrix[3][j];
            }
        }
        return product_vytrix;
    }
    void transpose(){
        type placeholder[4][4] = {{matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0]},
                                  {matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1]},
                                  {matrix[0][2], matrix[1][2], matrix[2][2], matrix[3][2]},
                                  {matrix[0][3], matrix[1][3], matrix[2][3], matrix[3][3]}};
        /*
        for(size_t i = 0; i < 4; ++i){
            for(size_t j = 0; j < 4; ++j){
                placeholder[j][i] = matrix[i][j];
            }
        }
        */
        memcpy(*matrix, *placeholder, sizeof(type)*16);
    }

    //TODO
    static void gaussian_eliminate_matrix(Vytrix<type> input_matrix){
        //Forward propagation
        for(size_t i = 0; i < 4; ++i){
            type pivot = input_matrix[i][i];
            if(pivot == 0){
                size_t curr_row = i; curr_row++;
                for(; curr_row < 4; ++curr_row){
                    if(input_matrix[curr_row][i] != 0){
                        SWAP_ROWS(input_matrix, curr_row, i);
                        --i; break;
                    }
                }
                continue;
            }
            pivot = 1/pivot;
            for(size_t j = 0; j < 4; ++j){
                input_matrix[i][j] *= pivot;
            }
            size_t curr_row = i; curr_row++;
            for(; curr_row< 4; ++curr_row){
                type multiplication_factor = input_matrix[curr_row][i];
                type subtraction_row[4] = {};
                memcpy(subtraction_row, input_matrix[i], sizeof(type)*4);
                subtraction_row[0] *= multiplication_factor; subtraction_row[1] *= multiplication_factor;
                subtraction_row[2] *= multiplication_factor; subtraction_row[3] *= multiplication_factor;
                input_matrix[curr_row][0] -= subtraction_row[0]; input_matrix[curr_row][1] -= subtraction_row[1];
                input_matrix[curr_row][2] -= subtraction_row[2]; input_matrix[curr_row][3] -= subtraction_row[3];
            }
        }
        input_matrix.print();
    }
    static type deg_to_rad(const type& deg){
        return (deg*M_PI)/180.0f;
    }
	static Vytrix<type> retrieve_translation_matrix(const type& x, const type& y, const type& z) {
		Vytrix<type> translation_matrix(1);
		translation_matrix[0][3] = x;
		translation_matrix[1][3] = y;
		translation_matrix[2][3] = z;
		return translation_matrix;
	}
	static Vytrix<type> retrieve_scaling_matrix(const type& x_scaler, const type& y_scaler, const type& z_scaler) {
		Vytrix<type> scaling_matrix(1);
		scaling_matrix[0][0] = x_scaler;
		scaling_matrix[1][1] = y_scaler;
		scaling_matrix[2][2] = z_scaler;
		return scaling_matrix;
	}
	static Vytrix<type> retrieve_x_rotation(const type& rad) {
		Vytrix<type> rotation_matrix({{ 1.0f, 0.0f, 0.0f, 0.0f }, {0.0f, cos(rad), sin(rad), 0.0f}, {0.0f,-sin(rad), cos(rad), 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}});
		return rotation_matrix;
	}
	static Vytrix<type> retrieve_y_rotation(const type& rad) {
		Vytrix<type> rotation_matrix({{ cos(rad), 0.0f, -sin(rad), 0.0f}, { 0.0f, 1.0f, 0.0f, 0.0f}, { sin(rad), 0.0f, cos(rad), 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}});
		return rotation_matrix;
	}
	static Vytrix<type> retrieve_z_rotation(const type& rad) {
		Vytrix<type> rotation_matrix({{ cos(rad), sin(rad), 0.0f, 0.0f }, { -sin(rad), cos(rad), 0.0f, 0.0f }, { 0.0f, 0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 0.0f, 1.0f}});
		return rotation_matrix;
	}
    void print(){
        std::cout<<&matrix<<std::endl;
        std::cout<<"[ " << matrix[0][0] << ", " << matrix[0][1] << ", " << matrix[0][2] << ", " << matrix[0][3]<<"]"<<std::endl;
        std::cout<<"| " << matrix[1][0] << ", " << matrix[1][1] << ", " << matrix[1][2] << ", " << matrix[1][3]<<"|"<<std::endl;
        std::cout<<"| " << matrix[2][0] << ", " << matrix[2][1] << ", " << matrix[2][2] << ", " << matrix[2][3]<<"|"<<std::endl;
        std::cout<<"[ " << matrix[3][0] << ", " << matrix[3][1] << ", " << matrix[3][2] << ", " << matrix[3][3]<<"]"<<std::endl;
    }
};


template <typename type>
class Vypoint{
    public:
    type vec[4] {};
    Vypoint(){};
    Vypoint(const type (&input)[4]){
        vec[0] = input[0];
        vec[1] = input[1];
        vec[2] = input[2];
        vec[3] = input[3];
    }
    Vypoint(const type& x){vec[0] = x; vec[1] = x; vec[2] = x; vec[3] = x;}
    type operator [] (const uint32_t i) {return vec[i];}
    const type operator [] (const uint32_t i) const {return vec[i];}
    Vypoint<type> operator * (Vytrix<type>& rh_matrix){
        Vypoint<type> v_point;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                v_point.vec[i] += vec[j]*rh_matrix[j][i];
            }
        }
        return v_point;
    }
    /*
        Assumes v[3] = w to be 1 to save multiplication operation
    */
    void multiplyBy4x4(Vytrix<type>& lh_matrix){
        type vec_prime[4] = {};
        vec_prime[0] = vec[0]*lh_matrix[0][0] + vec[1]*lh_matrix[1][0] + vec[2]*lh_matrix[2][0] + lh_matrix[3][0];
        vec_prime[1] = vec[0]*lh_matrix[0][1] + vec[1]*lh_matrix[1][1] + vec[2]*lh_matrix[2][1] + lh_matrix[3][1];
        vec_prime[2] = vec[0]*lh_matrix[0][2] + vec[1]*lh_matrix[1][2] + vec[2]*lh_matrix[2][2] + lh_matrix[3][2];
        vec_prime[3] = vec[0]*lh_matrix[0][3] + vec[1]*lh_matrix[1][3] + vec[2]*lh_matrix[2][3] + lh_matrix[3][3];
        if(vec[3] != 1 && vec[3] != 0){
            vec_prime[0]/=vec_prime[3]; vec_prime[1]/=vec_prime[3]; vec_prime[2]/=vec_prime[3];
        }
        memcpy(vec, vec_prime, sizeof(type)*4);
    }
    type dot_product(Vypoint<type>& v){
        return vec[0]*v[0] + vec[1]*v[1] + vec[2]*v[2];
    }
    Vypoint<type> x_product(Vypoint<type>& v){
        Vypoint<type> resultant_vypoint({vec[1]*v[2] - vec[2]*v[1], 
                                         vec[2]*v[0] - vec[0]*v[2],
                                         vec[0]*v[1] - vec[1]*v[0],
                                         1.0f});
        return resultant_vypoint; 
    }
    void add_vector(const Vypoint<type>& v){
        vec[0] += v[0]; vec[1] += v[1]; vec[2] += v[2];
    }
    void subtract_vector(const Vypoint<type>& v){
        vec[0] -= v[0]; vec[1] -= v[1]; vec[2] -= v[2];
    }
    void multiply_scalar(const type& r){
        vec[0] *= r; vec[1] *= r; vec[2] *= r;
    }
    void normalize_vector(){
        type length = vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2];
        if(length > 0){
            type inv_length = 1/sqrt(length);
            vec[0] *= inv_length; vec[1] *= inv_length; vec[2] *= inv_length;
        }
    }
    void print(){
        std::cout<<vec<<std::endl;
        std::cout<<"[ "<<vec[0]<<", "<<vec[1]<<", "<<vec[2]<<", "<<vec[3]<<"]"<<std::endl;
    }
};
