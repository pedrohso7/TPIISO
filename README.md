# TPIISO

# PARA EXECUTAR O PROGRAMA, EXECUTE O CÓDIGO NO TERMINAL: 

# 1) -> Essa linha de comando compila o código main.c e cria um executável exec.run:

terminal/bla/bla/bla/pastaDoProjeto$: gcc ProcessControle.c -pthread -o exec 

# 2) -> Essa linha executa o código compilado. PS: O código é exibido no terminal em que são executados os comandos:

terminal/bla/bla/bla/pastaDoProjeto$: ./exec 

#PARA COMMITAR SUA ALTERAÇÃO, PASSO A PASSO:

# 1) -> Essa linha de comando adiciona todos os arquivos que você realizou alteração para a "zona de commit":

terminal/bla/bla/bla/pastaDoProjeto$: git add .

# 2) -> Essa linha de comando faz o commit (Uma espécie de registro dessas alterações que você adicionou no passo anterior) na sua branch local (repositório que você clonou) e envia uma mensagem descritiva das alterações que você fez, enviar mensagem é opcional mas fortemente recomendado:

terminal/bla/bla/bla/pastaDoProjeto$: git commit -m "mensagem descritiva das alterações que você fez"

# 3) -> Neste momento, falta você enviar suas alterações para a branch remota (a oficial, do repositório):

terminal/bla/bla/bla/pastaDoProjeto$: git push

# 4) Entretando, podem ocorrer algumas coisas: o git pode te avisar que sua branch está atrasada em relação a branch remota, ou seja, enviaram alterações e você ainda não as baixou. Logo, você terá que fazer isso antes de enviar, mas não se preocupe, tá tudo bem. Basta "dar pull":

terminal/bla/bla/bla/pastaDoProjeto$: git pull

# Esse comando requisita ao git para baixar a última alteração salva na branch remota (recomendo usarem todas as vezes em que for mexer no código para procurar usar sempre a versão mais atualizada do nosso trabalho) e então você terá que fazer o merge ("juntar as partes") com as alterações que você fez localmente. Se não existir conflito (Alterações no mesmo arquivo que você também mexeu), basta realizar um commit (explicado nos passos anteriores) dizendo "faz o merge e bla bla bla". Entretanto, se existir conflito você terá que resolvê-lo antes de realizar o commit (recomendo usarem o vscode pois ele facilita bastante essa questão de resolver conflitos, basta clicar nos arquivos listados por ele que tiveram conflito e ele irá mostrar a região e oferecer três opções: aceitar as suas alterações apenas, aceitar apenas as alterações advindas da branch remota ou aceitar ambas. Vocês devem ter cautela para escolher nessa parte, rs!).

# Feito isso, pronto, agora está permitido usar o push:

terminal/bla/bla/bla/pastaDoProjeto$: git push

# PRINCIPAIS DECISÕES DE PROJETO:

#...
