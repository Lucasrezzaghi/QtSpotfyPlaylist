# QtSpotfyPlaylist
Programa feito em qt c++ para criar e executar uma playlist do spotify.

## Para Funcionar
Primeiramente é fundamental criar suas chaves para utilização da api do spotify(https://developer.spotify.com/dashboard/), logo após, atualizar o arquivo keys.h com as suas respectivas chaves. Quando o programa for aberto, clicar no botão "login" para autorizar a suas credencias

Caso ocorra o erro "invalid uri", crie um novo redirect URI no seu dashboard(https://developer.spotify.com/dashboard/) com o valor do uri de: "http://127.0.0.1:8080/".

## Funcionalidades
É possivel procurar a música desejada e adicionar a uma playlist, podendo tocar a playlist de forma sequencial ou aleatória com a fucionalidade de pular para proxima música ou voltar para músicas anteriores. O programa também tem a capacidade de salvar a playlist para que não se perca nada quando o programa for fechado.
