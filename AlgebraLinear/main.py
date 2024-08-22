from PIL import Image

def image_to_m(caminho):
    imagem = Image.open(caminho).convert('L') 
    largura, altura = imagem.size
    matriz = []
    for _ in range(altura):
        linha = []
        for _ in range(largura):
            linha.append(0)
        matriz.append(linha)
    
    for y in range(altura):
        for x in range(largura):
            matriz[y][x] = imagem.getpixel((x, y))
    
    return matriz, largura, altura

def aplicar_kernel(matriz, largura, altura, kernel):
    altura_kernel = len(kernel)
    largura_kernel = len(kernel[0])
    nova_matriz = []
    for _ in range(altura):
        linha = []
        for _ in range(largura):
            linha.append(0)
        nova_matriz.append(linha)

    for y in range(altura):
        for x in range(largura):
            soma = 0
            for ky in range(altura_kernel):
                for kx in range(largura_kernel):
                    px = x + kx - largura_kernel // 2
                    py = y + ky - altura_kernel // 2

                    if 0 <= px < largura and 0 <= py < altura:
                        pixel = matriz[py][px]
                    else:
                        pixel = 0  

                    soma += pixel * kernel[ky][kx]

            nova_matriz[y][x] = max(0, min(255, int(soma)))

    return nova_matriz

def salvar_matriz_como_imagem(matriz, largura, altura, caminho):
    imagem = Image.new('L', (largura, altura))
    
    for y in range(altura):
        for x in range(largura):
            imagem.putpixel((x, y), matriz[y][x])
    
    imagem.save(caminho)

def main():
    kernel_borda = [
        [-1, -1, -1],
        [-1,  8, -1],
        [-1, -1, -1]
    ]

    kernel_blur = [
        [1/9, 1/9, 1/9],
        [1/9, 1/9, 1/9],
        [1/9, 1/9, 1/9]
    ]

    kernel_relevo = [
        [-2, -1,  0],
        [-1,  1,  1],
        [ 0,  1,  2]
    ]


    # Borda
    matriz_pixels, largura, altura = image_to_m('image01.png')
    matriz_borda = aplicar_kernel(matriz_pixels, largura, altura, kernel_borda)
    salvar_matriz_como_imagem(matriz_borda, largura, altura, 'image01Edge.png')

    # Blur
    matriz_borda_pixels, _, _ = image_to_m('image01.png')
    matriz_blur = aplicar_kernel(matriz_borda_pixels, largura, altura, kernel_blur)
    salvar_matriz_como_imagem(matriz_blur, largura, altura, 'image01Blur.png')

    # Relevo
    matriz_borda_pixels, _, _ = image_to_m('image01.png')
    matriz_blur = aplicar_kernel(matriz_borda_pixels, largura, altura, kernel_relevo)
    salvar_matriz_como_imagem(matriz_blur, largura, altura, 'image01Relevo.png')

if __name__ == '__main__':
    main()