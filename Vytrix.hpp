#pragma once
#include <cmath>
#include <iostream>

template <typename type>
class Vytrix{
    type matrix[4][4] {};
    public:
    Vytrix(){}
    Vytrix(const type (&input)[4][4]){
        for(size_t i = 0; i < 4; ++i){
            for(size_t j = 0; j < 4; ++j){
                matrix[i][j] = input[i][j];
            }
        }
    }
    Vytrix(const uint32_t flag){
        if(flag == 1){
            matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
            matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
            matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
            matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
        }
    }
    type* operator [] (uint32_t i) {return matrix[i];}
    Vytrix operator * (Vytrix rh_matrix){
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
    Vypoint(const type x){vec[0] = x; vec[1] = x; vec[2] = x; vec[3] = x;}
    type operator [] (const uint32_t i) {return vec[i];}
    Vypoint operator * (Vytrix<type> rh_matrix){
        Vypoint<type> v_point;
        for(int i = 0; i < 4; ++i){
            for(int j = 0; j < 4; ++j){
                v_point.vec[i] += vec[j]*rh_matrix[j][i];
            }
        }
        return v_point;
    }
    type dot_product(Vypoint<type>& v){
        return vec[0]*v[0] + vec[1]*v[1] + vec[2]*v[2];
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
