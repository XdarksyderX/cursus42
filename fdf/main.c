#include "../mlx_linux/mlx.h"
#include <math.h>

void	draw_circle(void *mlx, void *win, int r, int h, int k)
{
	double theta;
	int x;
	int y;

	theta = 0;
	x = (int) round(r * cos(theta) + h);
	y = (int) round(r * sin(theta) + k);
	while (theta <= 2 * M_PI)
	{
		mlx_pixel_put(mlx, win, x, y, 0xFFFF);
		theta += 2 * M_PI / (800 * 600);
		x = (int) round(r * cos(theta) + h);
		y = (int) round(r * sin(theta) + k);
	}
}
int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "MiniLibX");
	draw_circle(mlx, win, 400, 400, 300);

	mlx_loop(mlx);
}
