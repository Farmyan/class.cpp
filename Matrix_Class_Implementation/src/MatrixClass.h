#include <algorithm> // for std::copy
#include <functional> // for std::plus, std::minus
#include <utility>   // for std::swap

template <typename T>
class MatrixClassBase
    {
        protected:
            int rows;
            int cols;
            T* data;
            MatrixClassBase() : rows(0) , cols(0) , data(nullptr) {};
            
            MatrixClassBase(int r , int c) : rows(r) , cols(c) , data(nullptr)
                {
                    data = new T[rows * cols];
                    for(int i = 0 ; i < rows * cols ; i++)
                        {
                            data[i] = T();
                        }
                }

            ~MatrixClassBase()
                {
                    delete[] data;
                }   

            MatrixClassBase(const MatrixClassBase& other) : rows(other.rows), cols(other.cols), data(nullptr)
                {
                    data = new T[rows * cols];
                    std::copy(other.data, other.data + rows * cols, data);
                }
            MatrixClassBase& operator=(const MatrixClassBase& other)
                {
                    if (this != &other)
                        {
                            MatrixClassBase temp(other); 
                            std::swap(rows, temp.rows);
                            std::swap(cols, temp.cols);
                            std::swap(data, temp.data);
                        }
                    return *this;
                }
            MatrixClassBase(MatrixClassBase&& other) : rows(other.rows) , cols(other.cols) , data(other.data)
                {
                    other.rows = 0;
                    other.cols = 0;
                    other.data = nullptr;
                }
            MatrixClassBase& operator=(MatrixClassBase&& other) 
                {
                    if(this != &other)
                        {
                            delete[] data;
                            data = other.data;
                            rows = other.rows;
                            cols = other.cols;
                            other.rows = 0;
                            other.cols = 0;
                            other.data = nullptr;
                        }
                    return *this;
                }
         public:
            class IndexOutOfBoundsException
            {
                public:
                    const char* what() const 
                        {  
                            return "Index out of bounds"; 
                        }
            };

            class SizeMismatchException
                {
                    public:
                        const char* what() const 
                            { 
                                return "Matrix size mismatch"; 
                            }
                };

            class InvalidMultiplicationException
                {
                    public:
                        const char* what() const 
                            { 
                                return "Invalid matrix multiplication dimensions"; 
                            }
                };


    };
template <typename T>
class MatrixClass : protected MatrixClassBase<T>
    {
        public:
            MatrixClass(int r , int c) : MatrixClassBase<T>(r , c ){}
            T& at(int r , int c)
                {
                    if((r < 0 || r >= this->rows) || (c < 0 || c >= this->cols))
                        {
                            throw  typename MatrixClassBase<T>::IndexOutOfBoundsException();
                        }
                    return  this->data[r * this->cols + c ];
                }

            const T& at(int r , int c) const
                {
                    if(r < 0 || r >= this->rows || c < 0 || c >= this->cols)
                        {
                            throw  typename MatrixClassBase<T>::IndexOutOfBoundsException();
                        }
                    return  this->data[r * this->cols + c ];
                }

            MatrixClass operator+(const MatrixClass& other) const
                {
                    if (this->rows != other.rows || this->cols != other.cols)
                        {
                            throw typename MatrixClassBase<T>::SizeMismatchException();
                        }
                    MatrixClass res(this->rows, this->cols);
                    std::transform(this->data, this->data + this->rows * this->cols, other.data, res.data, std::plus<T>());
                    return res;
                }
            MatrixClass operator-(const MatrixClass& other) const
                {
                    if (this->rows != other.rows || this->cols != other.cols)
                        {
                            throw typename MatrixClassBase<T>::SizeMismatchException();
                        }
                    MatrixClass res(this->rows, this->cols);
                    std::transform(this->data, this->data + this->rows * this->cols, other.data, res.data, std::minus<T>());
                    return res;
                }

            MatrixClass operator*(const MatrixClass& other)
                {
                    if(this->cols != other.rows)
                        {
                           throw typename MatrixClassBase<T>::InvalidMultiplicationException();
                        }
                    MatrixClass res(this->rows , other.cols);
                    for(int i = 0 ; i < this->rows ; i++)
                        {
                            for(int j = 0 ; j < other.cols ; j++)
                                {
                                    T sum = T();
                                    for(int k = 0 ; k < this->cols ; k++)
                                        {
                                            sum = sum + at(i , k ) * other.at(k , j);
                                        }
                                    res.at(i , j ) = sum;
                                }
                        }
                    return res;
                }
            MatrixClass transpose() const
                {
                    MatrixClass res(this->cols , this->rows);
                    
                        for(int i = 0 ; i < this->rows ; i ++)
                            {
                                for(int j = 0 ; j < this->cols ; j++)
                                    {
                                        res.at(j , i) = at(i , j);
                                    }
                            }
                        return res;
                } 
    };
