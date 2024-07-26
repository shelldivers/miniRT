```c
void *mlx_new_image ( 
	void *mlx_ptr, int width, int height );
```   

메모리에 새로운 image를 생성   

이미지를 조작하는데 필요한 식별자 반환   


```c
char *mlx_get_data_addr ( 
	void *img_ptr, int *bits_per_pixel, int *size_line, int *endian );
```   

생성된 이미지에 대한 정보를 반환하여 나중에 사용자가 이미지를 수정할 수 있도록 함   
void *imp_ptr - 사용할 이미지 지정   
int	*bits_per_pixel - 픽셀 색상을 표현하는데 필요한 비트 수
int	*size_line - 메모리에서 한 줄의 크기
int *endian - 이미지의 엔디안 방식

이미지 데이터가 저장된 메모리 영역의 시작 주소

```c
int mlx_put_image_to_window ( 
	void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y );
```   

만들어진 이미지를 window에 띄움   

```c
unsigned int mlx_get_color_value ( 
	void *mlx_ptr, int color );
```   

RGB색상 값을 적절한 비트 형식으로 변환

unsigned int 로 반환

```c
int mlx_destroy_image ( void *mlx_ptr, void *img_ptr );
```   

주어진 이미지를 파괴한다


