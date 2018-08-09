#pragma once
#include <cmath>
#include <iostream>
template <typename type>
class Vytrix{
    public:
    type matrix[4][4] = {};
    Vytrix(){

    }
    Vytrix(const type (&input)[4][4]){
        memcpy(matrix[0], input[0], sizeof(type) * 4);
        memcpy(matrix[1], input[1], sizeof(type) * 4);
        memcpy(matrix[2], input[2], sizeof(type) * 4);
        memcpy(matrix[3], input[3], sizeof(type) * 4);
    }
    Vytrix(const Vytrix<type>& copy_vytrix){
        memcpy(matrix[0], copy_vytrix.matrix[0], sizeof(type) * 4);
        memcpy(matrix[1], copy_vytrix.matrix[1], sizeof(type) * 4);
        memcpy(matrix[2], copy_vytrix.matrix[2], sizeof(type) * 4);
        memcpy(matrix[3], copy_vytrix.matrix[3], sizeof(type) * 4);
        #ifndef NDEBUG
            std::cout<<"Vytrix: Invoked copy constructor."<<std::endl;
            this->print();
        #endif
    }
    Vytrix(const uint32_t flag){
        if(flag == 1){
            matrix[0][0] = 1.0f; matrix[1][1] = 1.0f; matrix[2][2] = 1.0f; matrix[3][3] = 1.0f;
        }
    }
    type* operator [] (uint32_t i) {return matrix[i];}
    const type* operator [] (uint32_t i) const {return matrix[i];}
    /*Vytrix operator * (Vytrix& rh_matrix) { //rolled, compiler auto unrolls
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
    }*/
    Vytrix operator * (Vytrix& rh_matrix){
        Vytrix product_vytrix;
        product_vytrix[0][0] = this->matrix[0][0]*rh_matrix[0][0] +
                                this->matrix[0][1]*rh_matrix[1][0] +
                                this->matrix[0][2]*rh_matrix[2][0] +
                                this->matrix[0][3]*rh_matrix[3][0];
        product_vytrix[0][1] = this->matrix[0][0]*rh_matrix[0][1] +
                                this->matrix[0][1]*rh_matrix[1][1] +
                                this->matrix[0][2]*rh_matrix[2][1] +
                                this->matrix[0][3]*rh_matrix[3][1];
        product_vytrix[0][2] = this->matrix[0][0]*rh_matrix[0][2] +
                                this->matrix[0][1]*rh_matrix[1][2] +
                                this->matrix[0][2]*rh_matrix[2][2] +
                                this->matrix[0][3]*rh_matrix[3][2];  
        product_vytrix[0][3] = this->matrix[0][0]*rh_matrix[0][3] +
                                this->matrix[0][1]*rh_matrix[1][3] +
                                this->matrix[0][2]*rh_matrix[2][3] +
                                this->matrix[0][3]*rh_matrix[3][3];        
        product_vytrix[1][0] = this->matrix[1][0]*rh_matrix[0][0] +
                                this->matrix[1][1]*rh_matrix[1][0] +
                                this->matrix[1][2]*rh_matrix[2][0] +
                                this->matrix[1][3]*rh_matrix[3][0];
        product_vytrix[1][1] = this->matrix[1][0]*rh_matrix[0][1] +
                                this->matrix[1][1]*rh_matrix[1][1] +
                                this->matrix[1][2]*rh_matrix[2][1] +
                                this->matrix[1][3]*rh_matrix[3][1];
        product_vytrix[1][2] = this->matrix[1][0]*rh_matrix[0][2] +
                                this->matrix[1][1]*rh_matrix[1][2] +
                                this->matrix[1][2]*rh_matrix[2][2] +
                                this->matrix[1][3]*rh_matrix[3][2];  
        product_vytrix[1][3] = this->matrix[1][0]*rh_matrix[0][3] +
                                this->matrix[1][1]*rh_matrix[1][3] +
                                this->matrix[1][2]*rh_matrix[2][3] +
                                this->matrix[1][3]*rh_matrix[3][3];        
        product_vytrix[2][0] = this->matrix[2][0]*rh_matrix[0][0] +
                                this->matrix[2][1]*rh_matrix[1][0] +
                                this->matrix[2][2]*rh_matrix[2][0] +
                                this->matrix[2][3]*rh_matrix[3][0];
        product_vytrix[2][1] = this->matrix[2][0]*rh_matrix[0][1] +
                                this->matrix[2][1]*rh_matrix[1][1] +
                                this->matrix[2][2]*rh_matrix[2][1] +
                                this->matrix[2][3]*rh_matrix[3][1];
        product_vytrix[2][2] = this->matrix[2][0]*rh_matrix[0][2] +
                                this->matrix[2][1]*rh_matrix[1][2] +
                                this->matrix[2][2]*rh_matrix[2][2] +
                                this->matrix[2][3]*rh_matrix[3][2];  
        product_vytrix[2][3] = this->matrix[2][0]*rh_matrix[0][3] +
                                this->matrix[2][1]*rh_matrix[1][3] +
                                this->matrix[2][2]*rh_matrix[2][3] +
                                this->matrix[2][3]*rh_matrix[3][3];         
        product_vytrix[3][0] = this->matrix[3][0]*rh_matrix[0][0] +
                                this->matrix[3][1]*rh_matrix[1][0] +
                                this->matrix[3][2]*rh_matrix[2][0] +
                                this->matrix[3][3]*rh_matrix[3][0];
        product_vytrix[3][1] = this->matrix[3][0]*rh_matrix[0][1] +
                                this->matrix[3][1]*rh_matrix[1][1] +
                                this->matrix[3][2]*rh_matrix[2][1] +
                                this->matrix[3][3]*rh_matrix[3][1];
        product_vytrix[3][2] = this->matrix[3][0]*rh_matrix[0][2] +
                                this->matrix[3][1]*rh_matrix[1][2] +
                                this->matrix[3][2]*rh_matrix[2][2] +
                                this->matrix[3][3]*rh_matrix[3][2];  
        product_vytrix[3][3] = this->matrix[3][0]*rh_matrix[0][3] +
                                this->matrix[3][1]*rh_matrix[1][3] +
                                this->matrix[3][2]*rh_matrix[2][3] +
                                this->matrix[3][3]*rh_matrix[3][3];  
        return product_vytrix;
    }
    Vytrix operator * (const Vytrix& rh_matrix) const {
        Vytrix product_vytrix;
        product_vytrix[0][0] = this->matrix[0][0]*rh_matrix[0][0] +
                                this->matrix[0][1]*rh_matrix[1][0] +
                                this->matrix[0][2]*rh_matrix[2][0] +
                                this->matrix[0][3]*rh_matrix[3][0];
        product_vytrix[0][1] = this->matrix[0][0]*rh_matrix[0][1] +
                                this->matrix[0][1]*rh_matrix[1][1] +
                                this->matrix[0][2]*rh_matrix[2][1] +
                                this->matrix[0][3]*rh_matrix[3][1];
        product_vytrix[0][2] = this->matrix[0][0]*rh_matrix[0][2] +
                                this->matrix[0][1]*rh_matrix[1][2] +
                                this->matrix[0][2]*rh_matrix[2][2] +
                                this->matrix[0][3]*rh_matrix[3][2];  
        product_vytrix[0][3] = this->matrix[0][0]*rh_matrix[0][3] +
                                this->matrix[0][1]*rh_matrix[1][3] +
                                this->matrix[0][2]*rh_matrix[2][3] +
                                this->matrix[0][3]*rh_matrix[3][3];        
        product_vytrix[1][0] = this->matrix[1][0]*rh_matrix[0][0] +
                                this->matrix[1][1]*rh_matrix[1][0] +
                                this->matrix[1][2]*rh_matrix[2][0] +
                                this->matrix[1][3]*rh_matrix[3][0];
        product_vytrix[1][1] = this->matrix[1][0]*rh_matrix[0][1] +
                                this->matrix[1][1]*rh_matrix[1][1] +
                                this->matrix[1][2]*rh_matrix[2][1] +
                                this->matrix[1][3]*rh_matrix[3][1];
        product_vytrix[1][2] = this->matrix[1][0]*rh_matrix[0][2] +
                                this->matrix[1][1]*rh_matrix[1][2] +
                                this->matrix[1][2]*rh_matrix[2][2] +
                                this->matrix[1][3]*rh_matrix[3][2];  
        product_vytrix[1][3] = this->matrix[1][0]*rh_matrix[0][3] +
                                this->matrix[1][1]*rh_matrix[1][3] +
                                this->matrix[1][2]*rh_matrix[2][3] +
                                this->matrix[1][3]*rh_matrix[3][3];        
        product_vytrix[2][0] = this->matrix[2][0]*rh_matrix[0][0] +
                                this->matrix[2][1]*rh_matrix[1][0] +
                                this->matrix[2][2]*rh_matrix[2][0] +
                                this->matrix[2][3]*rh_matrix[3][0];
        product_vytrix[2][1] = this->matrix[2][0]*rh_matrix[0][1] +
                                this->matrix[2][1]*rh_matrix[1][1] +
                                this->matrix[2][2]*rh_matrix[2][1] +
                                this->matrix[2][3]*rh_matrix[3][1];
        product_vytrix[2][2] = this->matrix[2][0]*rh_matrix[0][2] +
                                this->matrix[2][1]*rh_matrix[1][2] +
                                this->matrix[2][2]*rh_matrix[2][2] +
                                this->matrix[2][3]*rh_matrix[3][2];  
        product_vytrix[2][3] = this->matrix[2][0]*rh_matrix[0][3] +
                                this->matrix[2][1]*rh_matrix[1][3] +
                                this->matrix[2][2]*rh_matrix[2][3] +
                                this->matrix[2][3]*rh_matrix[3][3];         
        product_vytrix[3][0] = this->matrix[3][0]*rh_matrix[0][0] +
                                this->matrix[3][1]*rh_matrix[1][0] +
                                this->matrix[3][2]*rh_matrix[2][0] +
                                this->matrix[3][3]*rh_matrix[3][0];
        product_vytrix[3][1] = this->matrix[3][0]*rh_matrix[0][1] +
                                this->matrix[3][1]*rh_matrix[1][1] +
                                this->matrix[3][2]*rh_matrix[2][1] +
                                this->matrix[3][3]*rh_matrix[3][1];
        product_vytrix[3][2] = this->matrix[3][0]*rh_matrix[0][2] +
                                this->matrix[3][1]*rh_matrix[1][2] +
                                this->matrix[3][2]*rh_matrix[2][2] +
                                this->matrix[3][3]*rh_matrix[3][2];  
        product_vytrix[3][3] = this->matrix[3][0]*rh_matrix[0][3] +
                                this->matrix[3][1]*rh_matrix[1][3] +
                                this->matrix[3][2]*rh_matrix[2][3] +
                                this->matrix[3][3]*rh_matrix[3][3];  
        return product_vytrix;
    }    
    void transpose(){
        type placeholder[4][4] = {{matrix[0][0], matrix[1][0], matrix[2][0], matrix[3][0]},
                                  {matrix[0][1], matrix[1][1], matrix[2][1], matrix[3][1]},
                                  {matrix[0][2], matrix[1][2], matrix[2][2], matrix[3][2]},
                                  {matrix[0][3], matrix[1][3], matrix[2][3], matrix[3][3]}};
        for(size_t i = 0; i < 4; ++i){
            for(size_t j = 0; j < 4; ++j){
                placeholder[j][i] = matrix[i][j];
            }
        }
        memcpy(*matrix, *placeholder, sizeof(type)*16);
    }
    inline bool invert(){
        return this->LU_decomposition_inversion();
    }
    inline static type deg_to_rad(const type& deg){
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
    inline static void SWAP_ROWS(type (&matrix)[4][4],size_t r1,size_t r2){ 
        /*
        type placeholder_row[4];
        memcpy(placeholder_row, matrix[r1], sizeof(type)*4);
        memcpy(matrix[r1], matrix[r2], sizeof(type)*4);
        memcpy(matrix[r2], placeholder_row, sizeof(type)*4);*/
        std::swap(matrix[r1][0], matrix[r2][0]);
        std::swap(matrix[r1][1], matrix[r2][1]);
        std::swap(matrix[r1][2], matrix[r2][2]);
        std::swap(matrix[r1][3], matrix[r2][3]);
    }
    static void SCALER_VECTOR_SUBTRACTION(type (&input_matrix)[4][4],type (&identity_matrix)[4][4], size_t target_row, size_t i){
        type multiplication_factor = input_matrix[target_row][i];
        type subtraction_row[4]; memcpy(subtraction_row, input_matrix[i], sizeof(type)*4);
        subtraction_row[0] *= multiplication_factor; subtraction_row[1] *= multiplication_factor;
        subtraction_row[2] *= multiplication_factor; subtraction_row[3] *= multiplication_factor;
        input_matrix[target_row][0] -= subtraction_row[0]; input_matrix[target_row][1] -= subtraction_row[1];
        input_matrix[target_row][2] -= subtraction_row[2]; input_matrix[target_row][3] -= subtraction_row[3];
        memcpy(subtraction_row, identity_matrix[i], sizeof(type)*4); //can optimize further
        subtraction_row[0] *= multiplication_factor; subtraction_row[1] *= multiplication_factor;
        subtraction_row[2] *= multiplication_factor; subtraction_row[3] *= multiplication_factor;
        identity_matrix[target_row][0] -= subtraction_row[0]; identity_matrix[target_row][1] -= subtraction_row[1];
        identity_matrix[target_row][2] -= subtraction_row[2]; identity_matrix[target_row][3] -= subtraction_row[3];
    }
    bool gaussian_inversion(){
        type original_matrix[4][4] = {};type iden_matrix[4][4] = {}; type determinent;
        memcpy(original_matrix[0], this->matrix[0], sizeof(type)*4);
        memcpy(original_matrix[1], this->matrix[1], sizeof(type)*4);
        memcpy(original_matrix[2], this->matrix[2], sizeof(type)*4);
        memcpy(original_matrix[3], this->matrix[3], sizeof(type)*4);
        iden_matrix[0][0] = 1.0f; iden_matrix[1][1] = 1.0f; iden_matrix[2][2] = 1.0f; iden_matrix[3][3] = 1.0f;
        //Forward propagation
        for(int i = 0; i < 4; ++i){ //Column iteration
            type pivot = original_matrix[i][i];
            if(pivot == 0){
                int target_row = i; target_row++;
                for(; target_row < 4; ++target_row){
                    if(original_matrix[target_row][i] != 0){
                        Vytrix<float>::SWAP_ROWS(original_matrix, target_row, i);
                        Vytrix<float>::SWAP_ROWS(iden_matrix, target_row, i);
                        --i; break;
                    }
                } continue;
            }
            pivot = 1/pivot;
            for(int j = 0; j < 4; ++j){ //Unify pivot and row
                original_matrix[i][j] *= pivot;
                iden_matrix[i][j] *= pivot;
            }
            int target_row = i; ++target_row;
            for(; target_row< 4; ++target_row){ //Rows below the rows of interest
                if(original_matrix[target_row][i] == 0){continue;}
                Vytrix<float>::SCALER_VECTOR_SUBTRACTION(original_matrix, iden_matrix, target_row, i);
            }
        }
        //Backward substitution
        for(int i = 3; i >= 0; i--){ //Column iteration
            type pivot = original_matrix[i][i];
            if(pivot == 0){continue;}
            int target_row = i; --target_row;
            for(; target_row >= 0; --target_row){ //Rows above the row of interest
                if(original_matrix[target_row][i] == 0){continue;}
                SCALER_VECTOR_SUBTRACTION(original_matrix, iden_matrix, target_row, i);     
            }
        }
        memcpy(this->matrix[0], iden_matrix[0], sizeof(type)*4);
        memcpy(this->matrix[1], iden_matrix[1], sizeof(type)*4);
        memcpy(this->matrix[2], iden_matrix[2], sizeof(type)*4);
        memcpy(this->matrix[3], iden_matrix[3], sizeof(type)*4);
        return true;
    }
    bool gaussian_inversion_alternate(){
        int i, j, k;
        type inv[4][4];
        type t[4][4];
        memcpy(t[0], this->matrix[0], sizeof(type)*4);
        memcpy(t[1], this->matrix[1], sizeof(type)*4);
        memcpy(t[2], this->matrix[2], sizeof(type)*4);
        memcpy(t[3], this->matrix[3], sizeof(type)*4);
        // Forward elimination
        for (i = 0; i < 3; i++) {
            int pivot = i;

            type pivotsize = t[i][i];

            if (pivotsize < 0)
                pivotsize = -pivotsize;

            for (j = i + 1; j < 4; j++) {
                type tmp = t[j][i];

                if (tmp < 0)
                    tmp = -tmp;

                if (tmp > pivotsize) {
                    pivot = j;
                    pivotsize = tmp;
                }
            }

            if (pivotsize == 0) {
                // Cannot invert singular matrix
                return false;
            }

            if (pivot != i) {
                for (j = 0; j < 4; j++) {
                    type tmp;

                    tmp = t[i][j];
                    t[i][j] = t[pivot][j];
                    t[pivot][j] = tmp;

                    tmp = inv[i][j];
                    inv[i][j] = inv[pivot][j];
                    inv[pivot][j] = tmp;
                }
            }

            for (j = i + 1; j < 4; j++) {
                type f = t[j][i] / t[i][i];

                for (k = 0; k < 4; k++) {
                    t[j][k] -= f * t[i][k];
                    inv[j][k] -= f * inv[i][k];
                }
            }
        }

        // Backward substitution
        for (i = 3; i >= 0; --i) {
            type f;

            if ((f = t[i][i]) == 0) {
                // Cannot invert singular matrix
                return false;
            }

            for (j = 0; j < 4; j++) {
                t[i][j] /= f;
                inv[i][j] /= f;
            }

            for (j = 0; j < i; j++) {
                f = t[j][i];

                for (k = 0; k < 4; k++) {
                    t[j][k] -= f * t[i][k];
                    inv[j][k] -= f * inv[i][k];
                }
            }
        }
        memcpy(this->matrix[0], inv[0], sizeof(type)*4);
        memcpy(this->matrix[1], inv[1], sizeof(type)*4);
        memcpy(this->matrix[2], inv[2], sizeof(type)*4);
        memcpy(this->matrix[3], inv[3], sizeof(type)*4);
        return true;
    }
    bool LU_decomposition_inversion(){ //MESA implementation of unrolled LU Decomposition Inversion
        type m[16], inv[16], det;
        memcpy(&m[0], this->matrix[0], sizeof(type)*4);
        memcpy(&m[4], this->matrix[1], sizeof(type)*4);
        memcpy(&m[8], this->matrix[2], sizeof(type)*4);
        memcpy(&m[12], this->matrix[3], sizeof(type)*4);
        int i;
        inv[0] = m[5]  * m[10] * m[15] - 
                m[5]  * m[11] * m[14] - 
                m[9]  * m[6]  * m[15] + 
                m[9]  * m[7]  * m[14] +
                m[13] * m[6]  * m[11] - 
                m[13] * m[7]  * m[10];
        inv[4] = -m[4]  * m[10] * m[15] + 
                m[4]  * m[11] * m[14] + 
                m[8]  * m[6]  * m[15] - 
                m[8]  * m[7]  * m[14] - 
                m[12] * m[6]  * m[11] + 
                m[12] * m[7]  * m[10];
        inv[8] = m[4]  * m[9] * m[15] - 
                m[4]  * m[11] * m[13] - 
                m[8]  * m[5] * m[15] + 
                m[8]  * m[7] * m[13] + 
                m[12] * m[5] * m[11] - 
                m[12] * m[7] * m[9];
        inv[12] = -m[4]  * m[9] * m[14] + 
                m[4]  * m[10] * m[13] +
                m[8]  * m[5] * m[14] - 
                m[8]  * m[6] * m[13] - 
                m[12] * m[5] * m[10] + 
                m[12] * m[6] * m[9];
        inv[1] = -m[1]  * m[10] * m[15] + 
                m[1]  * m[11] * m[14] + 
                m[9]  * m[2] * m[15] - 
                m[9]  * m[3] * m[14] - 
                m[13] * m[2] * m[11] + 
                m[13] * m[3] * m[10];
        inv[5] = m[0]  * m[10] * m[15] - 
                m[0]  * m[11] * m[14] - 
                m[8]  * m[2] * m[15] + 
                m[8]  * m[3] * m[14] + 
                m[12] * m[2] * m[11] - 
                m[12] * m[3] * m[10];
        inv[9] = -m[0]  * m[9] * m[15] + 
                m[0]  * m[11] * m[13] + 
                m[8]  * m[1] * m[15] - 
                m[8]  * m[3] * m[13] - 
                m[12] * m[1] * m[11] + 
                m[12] * m[3] * m[9];
        inv[13] = m[0]  * m[9] * m[14] - 
                m[0]  * m[10] * m[13] - 
                m[8]  * m[1] * m[14] + 
                m[8]  * m[2] * m[13] + 
                m[12] * m[1] * m[10] - 
                m[12] * m[2] * m[9];
        inv[2] = m[1]  * m[6] * m[15] - 
                m[1]  * m[7] * m[14] - 
                m[5]  * m[2] * m[15] + 
                m[5]  * m[3] * m[14] + 
                m[13] * m[2] * m[7] - 
                m[13] * m[3] * m[6];
        inv[6] = -m[0]  * m[6] * m[15] + 
                m[0]  * m[7] * m[14] + 
                m[4]  * m[2] * m[15] - 
                m[4]  * m[3] * m[14] - 
                m[12] * m[2] * m[7] + 
                m[12] * m[3] * m[6];
        inv[10] = m[0]  * m[5] * m[15] - 
                m[0]  * m[7] * m[13] - 
                m[4]  * m[1] * m[15] + 
                m[4]  * m[3] * m[13] + 
                m[12] * m[1] * m[7] - 
                m[12] * m[3] * m[5];
        inv[14] = -m[0]  * m[5] * m[14] + 
                m[0]  * m[6] * m[13] + 
                m[4]  * m[1] * m[14] - 
                m[4]  * m[2] * m[13] - 
                m[12] * m[1] * m[6] + 
                m[12] * m[2] * m[5];
        inv[3] = -m[1] * m[6] * m[11] + 
                m[1] * m[7] * m[10] + 
                m[5] * m[2] * m[11] - 
                m[5] * m[3] * m[10] - 
                m[9] * m[2] * m[7] + 
                m[9] * m[3] * m[6];
        inv[7] = m[0] * m[6] * m[11] - 
                m[0] * m[7] * m[10] - 
                m[4] * m[2] * m[11] + 
                m[4] * m[3] * m[10] + 
                m[8] * m[2] * m[7] - 
                m[8] * m[3] * m[6];
        inv[11] = -m[0] * m[5] * m[11] + 
                m[0] * m[7] * m[9] + 
                m[4] * m[1] * m[11] - 
                m[4] * m[3] * m[9] - 
                m[8] * m[1] * m[7] + 
                m[8] * m[3] * m[5];
        inv[15] = m[0] * m[5] * m[10] - 
                m[0] * m[6] * m[9] - 
                m[4] * m[1] * m[10] + 
                m[4] * m[2] * m[9] + 
                m[8] * m[1] * m[6] - 
                m[8] * m[2] * m[5];

        det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

        if (det == 0)
            return false;

        det = 1.0 / det;

        for (i = 0; i < 16; i++)
            inv[i] *= det;
        
        memcpy(this->matrix[0], &inv[0], sizeof(type)*4);
        memcpy(this->matrix[1], &inv[4], sizeof(type)*4);
        memcpy(this->matrix[2], &inv[8], sizeof(type)*4);
        memcpy(this->matrix[3], &inv[12], sizeof(type)*4);

        return true;
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
    void rotate_by_x(type rad){
        type vec_prime[4];
        vec_prime[0] = vec[0];
        vec_prime[1] = vec[1] * cos(rad) + vec[2]*(-sin(rad));
        vec_prime[2] = vec[1] * sin(rad) + vec[2]*cos(rad);
        memcpy(vec, vec_prime, sizeof(type)*4);
    }
    void rotate_by_y(type rad){
        type vec_prime[4];
        vec_prime[0] = vec[0]*cos(rad) + vec[2]*sin(rad);
        vec_prime[1] = vec[1];
        vec_prime[2] = vec[0]*(-sin(rad)) + vec[2]*cos(rad);
        memcpy(vec, vec_prime, sizeof(type)*4);
    }
    void rotate_by_z(type rad){
        type vec_prime[4];
        vec_prime[0] = vec[0]*cos(rad) + vec[1]*(-sin(rad));
        vec_prime[1] = vec[0]*sin(rad) + vec[1]*cos(rad);
        vec_prime[2] = vec[3];
        memcpy(vec, vec_prime, sizeof(type)*4);
    }
    inline type dot_product(Vypoint<type>& v){
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
