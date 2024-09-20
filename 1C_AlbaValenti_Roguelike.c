//Variables
int RespuestaInicio;
int Dia;
int Situacion_Tipo;
int RespuestaPregunta;
int RespuestaComerBeber;
int RespuestaBeber;
int RespuestaComer;
int RespuestaFinal;

//Varibles estadisticas
int VidaPlayer = 10;
int Agua = 4;
int Comida = 4;


// F U N C I O N  M A I N

void main()
{
    Inicio();
    if (RespuestaInicio == 1)
    {
        srand(time(0));
        Introduccion();
        getchar();
        system("cls");
        
        InfoJuego();
        getchar();
        system("cls");
        
        for (Dia = 1; Dia <=10; Dia++)
        {
            if (VidaPlayer > 0)
            {
                DrawInfo();
                Dibujos(0);
        
                GenerarSituacion();
                getchar();
                system("cls");
        
                DrawInfo();
                Pregunta(Situacion_Tipo);
                getchar();
                system("cls");
                if (VidaPlayer <= 0)
                {
                    GameOver();
                    break;
                }
                DrawInfo();
                ComerBeber();
                
                DrawInfo();
                AguaDisponible(Agua);
                ComidaDisponible(Comida);
                getchar();
                system("cls");
            
                VidaPlayer -= 1;
            }
            else
            {
                GameOver();
                break;
            }
        }
        if (VidaPlayer > 0)
        {
            Final();
        }
    }
    else if (RespuestaInicio == 2)
    {
        printf("Hasta la proxima!");
    }
    //Fin
    char a[32];
    scanf("%s",&a);
}


// F U N C I O N E S

void Inicio()
{
    printf("                                                 +@:               :@#.                                                       \n");
    printf("                                                 +@:               :@#.                                                       \n");
    printf("          *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@:               :@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*              \n");
    printf("          ##                                                                                                ##              \n");
    printf("          ##                                                                                               .##              \n");
    printf("          ##                                                                                               .##              \n");
    printf("          #@                    _______  __   __  __    _  ___   _  _______  _______                       .##              \n");
    printf("          ##                   |  _    ||  | |  ||  |  | ||   | | ||       ||    _  |                      .##              \n");
    printf("          ##                   | |_|   ||  | |  ||   |_| ||   |_| ||    ___||   | | |                      .##              \n");
    printf("          #@                   |       ||  |_|  ||       ||      _||   |___ |   |_| |_                     .##              \n");
    printf("          ##                   |  _   | |       ||  _    ||     |_ |    ___||    __   |                    .##              \n");
    printf("          ##                   | |_|   ||       || | |   ||    _  ||   |___ |   |  |  |                    .##              \n");
    printf("          ##                   |_______||_______||_|  |__||___| |_||_______||___|  | _|                    .##              \n");
    printf("          ##                                                                                               .##              \n");
    printf("          ##                                                                                               .##              \n");
    printf("          ##                                                                                               .##              \n");
    printf("          ##                                                  ----------          ----------               .##              \n");
    printf("          ##            Q U I E R E S    J U G A R  ?           1. SI                2. NO                 .##              \n");
    printf("          ##                                                  ----------          ----------               .##              \n");
    printf("          ##                                                                                               .##              \n");
    printf("          ##                                                                                               .##              \n");
    printf("          #@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#              \n");
    printf("          :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::.              \n\n\n");

    scanf("%d",&RespuestaInicio);
}

void Introduccion()
{
    printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");
    printf("|                                                                                                                                       |\n");
    printf("|   Nadie sabe como, pero la noche del 13 de diciembre se desprendieron unos gases contaminantes por toda la ciudad que arrasaron con   |\n");
    printf("|   todo aquel que los respiraba por unos segundos. Por suerte, tu obsesion con un hipotetico futuro apocalipsis zombie te llevo a      |\n");
    printf("|   crear un bunker bajo el jardin de tu casa anos atras. Aquella obsesion ya paso, pero ahora te das cuenta que las mil broncas de     |\n");
    printf("|   tu padre y horas y horas de trabajo no fueron en vano, pues en el momento que estar en la calle, e incluso dentro de casa empezo    |\n");
    printf("|   a ser peligroso para la supervivencia, no dudaste en refugiarte en el bunker. Ahora te encuentras solo y asustado dentro de cinco   |\n");
    printf("|   metros cuadrados ocupados por una cama, un armario y unas pocas provisiones. No sabes cuanto tiempo te espera aqui, solo que        |\n");
    printf("|   tienes que sobrevivir.                                                                                                              |\n");
    printf("|                                                                                                                                       |\n");
    printf(" ---------------------------------------------------------------------------------------------------------------------------------------\n");
    Continuar();
}

void InfoJuego()
{

    printf(" ___      _                                                                                         \n");
    printf("  |  ._ _|_ _  ._ ._ _   _.  _ o  _  ._     _  _  |_  ._ _     _  |    o      _   _   _             \n");
    printf(" _|_ | | | (_) |  | | | (_| (_ | (_) | |   _> (_) |_) | (/_   (/_ |    | |_| (/_ (_| (_)            \n");
    printf("                                                                      _|          _|                \n");
    printf("\n");
    printf("\n  ---------> DEBES SOBREVIVIR 10 DIAS EN EL BUNKER \n");
    printf("\n  ---------> CADA DIA QUE PASA, PIERDES 1 DE VIDA \n");
    printf("\n  ---------> LAS DECISIONES QUE TOMES ANTE LAS DIFERENTES SITUACIONES AFECTARAN A TU VIDA Y/O A TUS PROVISIONES\n");  //TERMINAR
    printf("\n  ---------> AL FINAL DE CADA DIA DEBERAS ESCOGER SI QUIERES COMER, BEBER O NINGUNA DE LAS DOS \n");
    printf("\n  ---------> EN EL BUNKER HAY 4 LATAS DE COMIDA Y 4 BOTELLAS DE AGUA. DEBES SABER GESTIONARLAS\n");
    printf("\n  ---------> LA COMIDA SUMA 2 DE DE VIDA Y EL AGUA SUMA 1 DE VIDA \n\n");
    Continuar();
}

void Continuar()
{
    printf("\nPresiona ENTER para continuar");
}

void GameOver()
{
    printf("       _______  _______  _______  _______            _______           _______  _______        \n");
    printf("      (  ____ \\(  ___  )(       )(  ____ \\          (  ___  )|\\     /|(  ____ \(  ____ )    \n");
    printf("      | (    \\/| (   ) || () () || (    \\/          | (   ) || )   ( || (    \\/| (    )|    \n");
    printf("      | |      | (___) || || || || (__              | |   | || |   | || (__    | (____)|       \n");
    printf("      | | ____ |  ___  || |(_)| ||  __)             | |   | |( (   ) )|  __)   |     __)       \n");
    printf("      | | \\_  )| (   ) || |   | || (                | |   | | \\ \\_/ / | (      | (\\ (      \n");
    printf("      | (___) || )   ( || )   ( || (____/\\          | (___) |  \\   /  | (____/\\| ) \ \\_    \n");
    printf("      (_______)|/     \\||/     \|(_______/          (_______)   \\_/   (_______/|/   \\__/    \n");    
}

void GenerarSituacion()
{
    Situacion_Tipo = rand() % 5;
    Situacion(Situacion_Tipo);
    Continuar();   
}

void Situacion(int Num)
{
    if (Num == 0)
    {
        printf(" -------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|       Has despertado por culpa de un pequeno temblor que no sabes de donde proviene.                  |\n");
        printf("|       Te levantas a mirar si quizas se debe a un problema de la ventilacion, pero de repente el       |\n");
        printf("|       temblor empieza a coger una fuerza que no te deja ni mantenerte en pie. Ahi es cuando te das    |\n");
        printf("|       cuenta de que se trata de un... TERREMOTO?!                                                     |\n");
        printf("|       Rapidamente miras a tu alrededor para ver que puedes hacer. Tienes que actuar rapido.           |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                               .:#+.                     ..        .+#.                                |\n");
        printf("|                              .=#*.       ....          -#*.      :##:.                                |\n");
        printf("|                             .##-.       .-#+.        .*@-.     .+@+.                                  |\n");
        printf("|                            -@#.        .=#=.       .=@*:.     .+@=.                                   |\n");
        printf("|                          .*@=.        .##:.      .:##=.      .*#-.                                    |\n");
        printf("|                         .#@.         .@#.        =@*.       .*#:                                      |\n");
        printf("|                         -#:.        -@*         #@:        .=#:                                       |\n");
        printf("|                         .##.       .#+         .@+.        .+#..                                      |\n");
        printf("|                          :#*.      .#@.         +@=.        :##-.                                     |\n");
        printf("|                           :@#.      .#@:.        -@#..       .=@+..                                   |\n");
        printf("|                            .##:      .+@+.        :##-.        :#@=.                                  |\n");
        printf("|                             .*@-.      :##:        .=#*:.        -#@=.                                |\n");
        printf("|                              .=@+.     ..##-.        :#@=.         :#@=.                              |\n");
        printf("|                               .-#*.      .=#*:        .=@*.          :##-.                            |\n");
        printf("|                                .+#-        :#*.         +@.           .=#:                            |\n");
        printf("|                                .+#:        .#+.        .##.          .:#*.                            |\n");
        printf("|                               .-#+.       .+@-.       .##.           .##:                             |\n");
        printf("|                               .+#-       .=@=.       :##:.          .##:                              |\n");
        printf("|                              .-@+.      .-#*.       :##:.          .##.                               |\n");
        printf("|                              .##.      .:##:       :##:.          .##.                                |\n");
        printf("|                              +#:       .=#-       :##:.          .##.                                 |\n");
        printf("|                             :@+.       .=#-      .:#=            .*@*.                                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf(" -------------------------------------------------------------------------------------------------------\n");
    }  
    else if (Num == 1)
    {
        printf(" -------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|       Empiezas a escuchar un ruido que viene de las tuberias. Parecen los pasos y los grunidos        |\n");
        printf("|       de algun animal. Deberias comprobarlo? Te asomas sigilosamente y ahi esta, un raton peludo      |\n");
        printf("|       y asustado pululeando por las tuberias en busca de algo de comer.                               |\n");
        printf("|       Sientes pena por ese raton, pues te recuerda a aquel hamster que tuviste de pequeno al que      |\n");
        printf("|       llamaste Timy. Debes hacer algo con ese animalito lo antes posible, pero el que?                |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                            .::::::.               .:-=+++*****+=-:                                    |\n");
        printf("|                        :+#@#*+*#@#===.      .=*#@#*+=--::::::-=+*###=.                                |\n");
        printf("|                      -##=.  -*@#*==-=+#@#:.+##+-.                   :+##=                             |\n");
        printf("|                     =@+   +@#-          +@@+:                          -#@=                           |\n");
        printf("|                     @#  -@#.             =@=                             :#@=                         |\n");
        printf("|                    .@* :@*                @#                               -@#.                       |\n");
        printf("|                     #@.+@-                #@                                .##.                      |\n");
        printf("|                  :+#@###@#                @#                                  ##.                     |\n");
        printf("|                =##=:    .*-              =@=                                  :#######+-              |\n");
        printf("|              =@#:                       +@+                                          .-*@*.           |\n");
        printf("|             #@-   @@             ..:=*@#:                       .##          +#####*-   *@=           |\n");
        printf("|           .##.   -@@             -##*+-                          ##          +@=   .=%@-  +@-          |\n");
        printf("|          =@*                                                    .@*        .#@-       *@:  @#         |\n");
        printf("|       .+#@-                               +#.                    @#      :#@*.        -@=  @#         |\n");
        printf("|       *@@@:   :=##:          .-+*=      .#@:    =#:              +@-     :@*          :@+ .@*         |\n");
        printf("|        ==+#@####@#=:.  .:-+#@#@@*-     :@#.    +@=        .:-=+*#@@@:     *@.         :@+ =@-         |\n");
        printf("|                  -+*####*+=:  .=*#####@@#     +@@##########*+=-:   #@:    +@:         .@* #@          |\n");
        printf("|                                      .@#     =@+                 :=*@+    *@.          #@.@#          |\n");
        printf("|                                   .-=#@.    -@*                .##+-.     @#           .@##@.         |\n");
        printf("|                                 .#@+=-.    :@*                 *@...:::-=*@=             *@@#         |\n");
        printf("|                                 *@:.....  .##                  +@###***+=-:               :#@#:       |\n");
        printf("|                                 -*##########:                                                *#       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf(" -------------------------------------------------------------------------------------------------------\n");
    }
    else if (Num == 2)
    {
        printf(" -------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|       Estabas a punto de acostarte cuando alguien toca a tu puerta. Decides abrir, sin estar muy      |\n");
        printf("|       seguro si es una buena decision. Detras de la puerta se encuentra un senor alto con barba       |\n");
        printf("|       que tiene un aire muy misterioso. Dice que se siente solo y extrana jugar a cartas con su       |\n");
        printf("|       amigo Ted, quien murio debido al apocalipsis. Te propone jugar una partida de cartas con el     |\n");
        printf("|       y que el ganador se lleve una lata de comida del perdedor.                                      |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                              ...  .:+***###*+=.                                                       |\n");
        printf("|                             .+#@@@@@@@@@@@@@@@@@##*:                                                  |\n");
        printf("|                          :#@@@@@@@@@@@@@@@@@@@@@@@@@@-                                                |\n");
        printf("|                       .=@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.                                              |\n");
        printf("|                      .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#.                                             |\n");
        printf("|                    .:@@@@@@@@@@##@@@@@@@@@@@@@@@@@@@@@@#-.                                            |\n");
        printf("|                  ...@@@@@@@@@@@#@@@@@@@@@@@@@@@@@@@@@@@@+.                                            |\n");
        printf("|                  . =@@@@@@@@@@@@@@@@@@@@@#:.   .*@@@@@@@+                                             |\n");
        printf("|                    *@@@@@@@@@@@@@@@@@@@#:.       -@@@@@@+                                             |\n");
        printf("|                    *@@@@@@@@@@@@@@@@@+.           :@@@@@-                                             |\n");
        printf("|                    +@@@@@@@@@@@@@#+.               *@@@@:                                             |\n");
        printf("|                   .-@@@@@@@@@#+....       ....     -@@@#...                                           |\n");
        printf("|                   ..#@@@@*.:#@@@@@+       ###@@@=.  #@@=.                                             |\n");
        printf("|                     :@@@*.*#*++*##.       +##*++##. :@@:                                              |\n");
        printf("|                     .*@@.  ...:..          ...:...  .##.                                              |\n");
        printf("|                  .@:.#@*  .#*#@@@=         *@@##:*   *@##+.                                           |\n");
        printf("|                 .=*@+#@+  =.@@@@@*      ..=#@@@@+-  .#@@@+=                                           |\n");
        printf("|                 -=*..:@+  .-*#@#+#.     :.=##@@=#:  -@@:.*=-                                          |\n");
        printf("|                 .=...+@+     .....      .=.....    .@@#:..=.                                          |\n");
        printf("|                  .+: *@#      ....       .-.       +@@@:.*.                @@@@@@@@@@@@@              |\n");
        printf("|                    ..#@@-      ...      .:.       :@@@@:..                 @ A       A @              |\n");
        printf("|                     .#@@@#++*#@@@@@@@@@@@@@@@@@@@#@@@@#.           @@@@@@@@@@@@@@      @              |\n");
        printf("|                      *@@@@@@@@@#. .........  #@@@@@@@@#.           @ 3        3 @ _    @              |\n");
        printf("|                      =@@@@@@@@@@#:.        .#@@@@@@@@@=            @     /\\     @' \\   @              |\n");
        printf("|                       @@@@@@@@@@@@@*=---=*#@#@@@@@@@@#.            @     \\/     @  /   @              |\n");
        printf("|                       =@@@@@@@@@@@@@@@@@@@@##@@@@@@@@:             @     /\\     @_/    @              |\n");
        printf("|                       .*@@@@@@@@@@@@@@@@@@@@@@@@@@@@:              @     \\/     @      @              |\n");
        printf("|                         :#@@@@@@@@@@@@@@@@@@@@@@@@*                @     /\\     @    A @              |\n");
        printf("|                           .=#@@@@@@@@@@@@@@@@@@#:                  @     \\/     @@@@@@@@              |\n");
        printf("|                               #.-+#######+-..##                    @ 3        3 @                     |\n");
        printf("|                               ##              ##                   @@@@@@@@@@@@@@                     |\n");
        printf("|                               ##              ##                                                      |\n");
        printf("|                               ##              ##                                                      |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf(" -------------------------------------------------------------------------------------------------------\n");
    }
    else if (Num == 3)
    {
        printf(" --- -------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                           |\n");
        printf("|                                                                                                           |\n");
        printf("|       Wow! Hacia tiempo que no se escuchaba tanto movimiento fuera del bunker. Se pueden distinguir       |\n");
        printf("|       claramente los pasos de lo que debe ser una gran manada de animales. Seran caballos, vacas,         |\n");
        printf("|       jabalis...? No lo sabras si no sales a comprobarlo. Lo que si sabes es que si lograras matar        |\n");
        printf("|       a alguno de ellos tendrias carne fresca para muchos dias!                                           |\n");
        printf("|       Todo lo que tienes para completar la mision es una mascara antigas y un cuchillo bien afilado.      |\n");
        printf("|       Dicen que quien no arriesga no gana, pero... vale la pena arriesgarse en esta ocasion?              |\n");
        printf("|                                                                                                           |\n");
        printf("|                                                                                                           |\n");
        printf("|                                                               __n__n__            .-'''-.__               |\n");
        printf("|               _____         |\\_/|,,_____,~~`           .------`-\\00/-'          /      ' o'\\              |\n");
        printf("|           ^..^     \\9       (.'.)~~     )`~}}         /  ##  ## (oo)          ,-;  '.  :   _c             |\n");
        printf("|           (oo)_____/         \\o/\\ /---~\\\\ ~}}        / \\ ## ___  ./           :_.'\\._ ) ::-'              |\n");
        printf("|              WW  WW            _//    _// ~}            |||   |||                   ''m 'm                |\n");
        printf("|       ..............................................................................................      |\n");
        printf("|       ##############################################################################################      |\n");
        printf("|                                              .@=         @#                                               |\n");      
        printf("|                                              .@=         @#                                               |\n");      
        printf("|                                              .@=         @#                                               |\n");      
        printf("|                         .+********************@=         @#*****************=                             |\n");      
        printf("|                         .##...::::::::::::::::::         :...::...:........##                             |\n");      
        printf("|                         .##                                                ##                             |\n");      
        printf("|                         .##                     .:=+:.                     ##                             |\n");      
        printf("|                         .@#                    .*@@@@#:                    ##                             |\n");       
        printf("|                         .##                    :@@@@@@-.                   ##                             |\n");       
        printf("|                         .##                     -@@@@+                     ##                             |\n");       
        printf("|                         .##                      .##.                      ##                             |\n");       
        printf("|                         .##                   .#@@@@@@*.                   ##                             |\n");       
        printf("|                         .##                  .@@+@@@@#@@.                  ##                             |\n");        
        printf("|                         .##                 .@# .@@@@#.+@.                 ##                             |\n");        
        printf("|                         .##                     .@@@@#.                   .##                             |\n");        
        printf("|                         .##                     .@@@@@.                    ##                             |\n");        
        printf("|                         .##                      @# #@                     ##                             |\n");        
        printf("|                         .##                      @# #@                     ##                             |\n");        
        printf("|                         .##......................@# #@.....................##                             |\n");        
        printf("|                         .*##################################################+.                            |\n");
        printf("|                                                                                                           |\n");
        printf("|                                                                                                           |\n");
        printf("|                                                                                                           |\n");
        printf(" -----------------------------------------------------------------------------------------------------------\n");
    }
    else if (Num == 4)
    {
        printf(" -------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|       Alguien esta tocando a tu puerta muy bruscamente y sin parar. Se oyen voces de dos personas,    |\n");
        printf("|       una de ellas de una nina pequena, quien no para de toser y quejarse. Parece que necesitan       |\n");
        printf("|       ayuda.                                                                                          |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                       / / /                                           |\n");
        printf("|                       /////////////||||               \\ \\ \\                                           |\n");
        printf("|                       ((((((((((((((||||              / / /                                           |\n");
        printf("|                       ))) ~~      ~~  (((                                                             |\n");
        printf("|                       ((( (*)     (*) )))          //////////||                                       |\n");
        printf("|                       )))     <       (((          (((((((((((||                                      |\n");
        printf("|                       (((   ______    )))          )) ~~   ~~ ((                                      |\n");
        printf("|                       )))\\___________/(((          (( (*) (*) ))                                      |\n");
        printf("|                              _) (_                 ((   ___   ))                                      |\n");
        printf("|                             / \\_/ \\                ))\\_______/((                                      |\n");
        printf("|                            /(     )\\                   _) (_                                          |\n");
        printf("|                           // )___( \\\\                 / \\_/ \\                                         |\n");
        printf("|                           \\\\(     )//                / |   |\\\\                                        |\n");
        printf("|                            (       )                // |___| \\\\                                       |\n");
        printf("|                             |  |  |                 \\\\|     |//                                       |\n");
        printf("|                              | | |                    |_____|                                         |\n");
        printf("|                              | | |                     | | |                                          |\n");
        printf("|                             _|_|_|_                   _|_|_|_                                         |\n");
        printf("|                                                                                                       |\n");
        printf("|                                                                                                       |\n");
        printf(" -------------------------------------------------------------------------------------------------------\n");
    }
}

void Pregunta(int Num)
{
    if (Num == 0)
    {
        printf("\n      Q U E   Q U I E R E S   H A C E R  ?\n\n\n");
        printf("                  ---------------------------------------------------------\n");
        printf("         ---->    1. Agarrarse a una pata de la mesa para mantenerte quieto\n");
        printf("                  ---------------------------------------------------------\n\n");
        printf("                  ---------------------------------------------------\n");
        printf("         ---->    2. Tumbarse en la cama hasta que termine el temblor\n");
        printf("                  ---------------------------------------------------\n\n");
        do
        {
            scanf("%d",&RespuestaPregunta);
        }
        while (RespuestaPregunta!=1 && RespuestaPregunta!=2);
        getchar();
        system("cls");
        if (RespuestaPregunta == 1)
        {
            DrawInfo();
            
            printf(" ---------------------------------------------------------------------------------------\n");
            printf("|  Has hecho bien. Te has agarrado con tanta fuerza que has  impedido que el movimiento |\n");
            printf("|  te mueva un solo centimetro.                                                         |\n");
            printf(" ---------------------------------------------------------------------------------------\n\n\n");
        }
        else if (RespuestaPregunta == 2)
        {
            VidaPlayer -= 2;
            DrawInfo();
            
            printf(" -------------------------------------------------------------------------------------\n");
            printf("|  Tumbarte en la cama no fue buena opcion. El temblor es tan fuerte que ha tumbado   |\n");
            printf("|  la estanteria situada al lado de la cama y esta ha caido encima de ti, causandote  |\n");
            printf("|  varias heridas y moratones por todo el cuerpo.                                     |\n");
            printf(" -------------------------------------------------------------------------------------\n\n\n");
            
            DibujosSumarRestar(0);
            
        }
    }
    else if (Num == 1)
    {
        printf("\n      Q U E   Q U I E R E S   H A C E R  ?\n\n\n");
        printf("                  ----------------------------------------------------------------------------\n");
        printf("         ---->    1. Matarlo con la escoba. La carne de ese raton podria ayudarme a sobrevivir\n");
        printf("                  ----------------------------------------------------------------------------\n\n");
        printf("                  -------------------------------------------------------------------------------------\n");
        printf("         ---->    2. Te lo quedas de mascota. No puedes dejar esa pobre bolita sobrevivir por su cuenta\n");
        printf("                  -------------------------------------------------------------------------------------\n\n");
        printf("                  ---------------------------------------------------\n");
        printf("         ---->    3. Cogerlo con las manos y sacarlo fuera del bunker\n");
        printf("                  ---------------------------------------------------\n\n");
        do
        {
            scanf("%d",&RespuestaPregunta);
        }
        while (RespuestaPregunta!=1 && RespuestaPregunta!=2 && RespuestaPregunta!=3);
        getchar();
        system("cls");

        if (RespuestaPregunta == 1)
        {
            DrawInfo();
            
            printf(" ---------------------------------------------------------------------------------------\n");
            printf("|  Uf! Ha sido agotador pero lo has logrado. Despues de varios minutos dando vueltas    |\n");
            printf("|  detras de ese bicho dentro de los escasos metros cuadrados de este bunker, has       |\n");
            printf("|  logrado golpearlo con tanta fuerza que se ha quedado tieso en el suelo boca arriba.  |\n");
            printf("|  Por desgracia, el golpe ha tenido tanta fuerza que ha aplastado la carne del raton   |\n");
            printf("|  y ahora es incomible. Has matado al pobre raton para nada!                           |\n");
            printf(" ---------------------------------------------------------------------------------------\n\n\n");
        }
        else if (RespuestaPregunta == 2)
        {
            Comida -= 1;
            DrawInfo();
            
            printf(" ---------------------------------------------------------------------------------------\n");
            printf("|  No debiste confiar en ese animal. Mientras le preparabas una pequena cama con unas   |\n");
            printf("|  telas que tenias por alli, el raton ha escapado llevandose con el una de tus latas   |\n");
            printf("|  de comida. Esto no lo viste venir!                                                   |\n");
            printf(" ---------------------------------------------------------------------------------------\n\n\n");
            
            DibujosSumarRestar(3);
        }
        else if (RespuestaPregunta ==3)
        {
            VidaPlayer -= 2;
            DrawInfo();
            
            printf(" ----------------------------------------------------------------------------------------\n");
            printf("|  Intentar agarrarlo con las manos no fue buena opcion. El raton se sintio atacado      |\n");
            printf("|  y salto con rabia a morderte el brazo. Menuda herida te ha provocado lo que parecia   |\n");
            printf("|  ser un animal inofensivo... Mirando por el lado bueno, despues de eso, el raton se    |\n");
            printf("|  marcho por su propia cuenta.                                                          |\n");
            printf(" ----------------------------------------------------------------------------------------\n\n\n");
            
            DibujosSumarRestar(0);
        }
    }
    else if (Num == 2)
    {
        printf("\n      Q U E   Q U I E R E S   H A C E R  ?\n\n\n");
        printf("                  --------------------------------------------------------------------\n");
        printf("         ---->    1. Acepto la partida. A mi tampoco me vendra mal un poco de compania\n");
        printf("                  --------------------------------------------------------------------\n\n");
        printf("                  -----------------------------------------------------------\n");
        printf("         ---->    2. Le cierro la puerta en la cara, no me inspira confianza!\n");
        printf("                  -----------------------------------------------------------\n\n");
        printf("                  ------------------------------------------------------------------------------------------------------------\n");
        printf("         ---->    3. Rechazo la oferta amablemente. Siento pensa por el senor, pero no me puedo arriesgar a perder provisiones\n");
        printf("                  ------------------------------------------------------------------------------------------------------------\n\n");
        do
        {
            scanf("%d",&RespuestaPregunta);
        }
        while (RespuestaPregunta!=1 && RespuestaPregunta!=2 && RespuestaPregunta!=3);
        getchar();
        system("cls");

        if (RespuestaPregunta == 1)
        {
            Comida += 1;
            DrawInfo();
            
            printf(" ---------------------------------------------------------------------------------------\n");
            printf("|  Ha sido una partida igualada pero finalmente has logrado ganar! El hombre con barba  |\n");
            printf("|  agradece enormemente tu compania y antes de marchar te ofrece encantado una lata de  |\n");
            printf("|  de carne en conserva.                                                                |\n");
            printf(" ---------------------------------------------------------------------------------------\n\n\n");
            
            DibujosSumarRestar(4);
        }
        else if (RespuestaPregunta == 2)
        {
            DrawInfo();
            
            printf(" ---------------------------------------------------------------------------------------\n");
            printf("|  Justo antes de cerrar la puerta puedes observar la cara de pena del hombre. Quiza    |\n");
            printf("|  no tenia ninguna mala intencion y solo queria pasar un rato en compania.             |\n");
            printf("|  Sin embargo, hoy en dia uno no sabe de quien se puede fiar y de quien no.            |\n");
            printf(" ---------------------------------------------------------------------------------------\n\n\n");
        }
        else if (RespuestaPregunta ==3)
        {
            Agua += 1;
            DrawInfo();
            
            printf(" ---------------------------------------------------------------------------------------\n");
            printf("|  El hombre misterioso entiende tu respuesta y se marcha sin problema, no sin antes    |\n");
            printf("|  ofrecerte una botella de agua por tu honestidad. Todavia queda gente buena en este   |\n");
            printf("|  mundo!                                                                               |\n");
            printf(" ---------------------------------------------------------------------------------------\n\n\n");
            
            DibujosSumarRestar(2);
        }
    }
    else if (Num == 3)
    {
        printf("\n      Q U E   Q U I E R E S   H A C E R  ?\n\n\n");
        printf("                  ------------------\n");
        printf("         ---->    1. Salir a la caza\n");
        printf("                  ------------------\n\n");
        printf("                  ------------------------\n");
        printf("         ---->    2. Quedarse en el bunker\n");
        printf("                  ------------------------\n\n");
        do
        {
            scanf("%d",&RespuestaPregunta);
        }
        while (RespuestaPregunta!=1 && RespuestaPregunta!=2);
        getchar();
        system("cls");

        if (RespuestaPregunta == 1)
        {
            VidaPlayer -= 3;
            DrawInfo();
            
            printf(" ---------------------------------------------------------------------------------------\n");
            printf("|  Saliste a la caza y volviste con las manos vacias de comida y el cuerpo lleno de     |\n");
            printf("|  heridas. Pensaste que seria buena idea atacar un jabali que estaba un poco alejado   |\n");
            printf("|  del grupo pero, en que momento creias que un cuchillo de bastaria para acabar con la |\n");
            printf("|  vida de un jabali tu solo? Al primer intento de rajarle, el animal se puso furioso   |\n");
            printf("|  y empezo a atacarte hasta el punto de dejarte en el suelo casi sin poder moverte.    |\n");
            printf("|  Por suerte decidio marchar y dejarte con vida. De no ser asi ahora estarias MUERTO!  |\n");
            printf("|  La proxima vez deberias pensar mas las cosas antes de actuar.                        |\n");
            printf(" ---------------------------------------------------------------------------------------\n\n\n");
            
            DibujosSumarRestar(1);
        }
        else if (RespuestaPregunta == 2)
        {
            DrawInfo();
            
            printf(" -------------------------------------------------------------------------------------------\n");
            printf("|  Decidiste permanecer en el bunker y... que buena idea! Las pisadas de animales tardaron  |\n");
            printf("|  tiempo en cesar, lo que significa que habia muchos de ellos. Ademas, se han oido varios  |\n");
            printf("|  rugidos que daban mucho miedo. Que iba a hacer alguien como tu peleando contra uno de    |\n");
            printf("|  esos animales feroces? Seguro que la cosa habria acabado mal.                            |\n");
            printf(" -------------------------------------------------------------------------------------------\n\n\n");
        }
    }
    else if (Num == 4)
    {
        printf("\n      Q U E   Q U I E R E S   H A C E R  ?\n\n\n");
        printf("                  ------------------\n");
        printf("         ---->    1. Abrir la puerta\n");
        printf("                  ------------------\n\n");
        printf("                  ---------------------\n");
        printf("         ---->    2. No abrir la puerta\n");
        printf("                  ---------------------\n\n");
        do
        {
            scanf("%d",&RespuestaPregunta);
        }
        while (RespuestaPregunta!=1 && RespuestaPregunta!=2);
        getchar();
        system("cls");

        if (RespuestaPregunta == 1)
        {
            VidaPlayer -= 2;
            DrawInfo();
            
            printf(" ----------------------------------------------------------------------------------------------\n");
            printf("|  Decidiste ir por el camino de la bondad y no salio bien. Abriste la puerta y te encontraste |\n");
            printf("|  a una madre con su hija en busca de medicinas para la pequena. Por desgracia, no dispones   |\n");
            printf("|  de ningun medicamiento para ofrecerles. Les has ofrecido algo de comida, pero no la han     |\n");
            printf("|  querido aceptar. Minutos despues te has empezado a encontrar mal de la garganta y a toser.  |\n");
            printf("|  La nina te ha pegado el virus! Ser buena persona te ha hecho pagar factura...               |\n");
            printf(" ----------------------------------------------------------------------------------------------\n\n\n");
            
            DibujosSumarRestar(0);
        }
        else if (RespuestaPregunta == 2)
        {
            DrawInfo();
            
            printf(" -----------------------------------------------------------------------------------------------\n");
            printf("|  Por mucha pena que sientas, no sabes que enfermedad puede tener esa nina, y abrir la puerta  |\n");
            printf("|  podria suponer un riesgo para tu salud. Ademas, no tienes ningun tipo de medicamiento que    |\n");
            printf("|  pueda ayudarla a curarse. Deberan ir en busca de ayuda a otro lado.                          |\n");
            printf(" -----------------------------------------------------------------------------------------------\n\n\n");
        }
    }
    Continuar();
    if (VidaPlayer <= 0)
    {
        getchar();
        system("cls");
        GameOver();
    }
}

void ComerBeber()
{
    if (Comida > 0 || Agua > 0)
    {
        printf("\n      Q U I E R E S   C O M E R   O   B E B E R  ?\n\n\n");
        printf("                  --------\n");
        printf("         ---->    1. Comer\n");
        printf("                  --------\n\n");
        printf("                  --------\n");
        printf("         ---->    2. Beber\n");
        printf("                  --------\n\n");
        printf("                  -----\n");
        printf("         ---->    3. No\n");
        printf("                  -----\n");
        do
        {
            scanf("%d",&RespuestaComerBeber);
        }
        while (RespuestaComerBeber!=1 && RespuestaComerBeber!=2 && RespuestaComerBeber!=3);
        getchar();
        system("cls");
        if (RespuestaComerBeber == 1)
        {
            if (Comida>0)
            {
                VidaPlayer += 2;
                Comida -= 1;
                if (VidaPlayer > 10)
                {
                    VidaPlayer = 10;
                }
                
            }
            else
            {
                printf("\n      N O   T E   Q U E D A   C O M I D A  ,  S O L O   A G U A  .  Q U I E R E S   B E B E R  ?\n\n\n");
                printf("                  -----\n");
                printf("         ---->    1. SI\n");
                printf("                  -----\n");
                printf("                  -----\n");
                printf("         ---->    2. NO\n");
                printf("                  -----\n");
                do
                {
                    scanf("%d",&RespuestaBeber);
                }
                while (RespuestaBeber!=1 && RespuestaBeber!=2);
                getchar();
                system("cls");
                if (RespuestaBeber == 1)
                {
                    VidaPlayer += 1;
                    Agua -= 1;
                    if (VidaPlayer > 10)
                    {
                        VidaPlayer = 10;
                    }
                }
            }
        }
        else if (RespuestaComerBeber == 2)
        {
            if (Agua>0)
            {
                VidaPlayer += 1;
                Agua -= 1;
            }
            else
            {
                printf("\n      N O   T E   Q U E D A   A G U A  ,  S O L O   CO M I D A  .  Q U I E R E S   C O M E R  ?\n\n\n");
                printf("                  -----\n");
                printf("         ---->    1. SI\n");
                printf("                  -----\n");
                printf("                  -----\n");
                printf("         ---->    2. NO\n");
                printf("                  -----\n");
                do
                {
                    scanf("%d",&RespuestaComer);
                }
                while (RespuestaComer!=1 && RespuestaComer!=2);
                getchar();
                system("cls");
                if (RespuestaComer == 1)
                {
                    VidaPlayer += 2;
                    Comida -= 1;
                }
            }
        }
    }    
}

void DrawInfo()
{
    if (VidaPlayer < 0)
    {
        VidaPlayer = 0;
    }
    if (Comida < 0)
    {
        Comida = 0;
    }
    if (Agua < 0)
    {
        Agua = 0;
    }
    printf("  DIAS SOBREVIVIENDO: %d\n",Dia);
    printf("  Vida: %d                                                                                                         Comida: %d     Agua: %d\n",VidaPlayer, Comida, Agua);
    printf("=============================================================================================================================================");
    printf("\n\n");
}

void Dibujos(int Num)
{
    if (Num == 0)
    {
        printf("  _______ __                               __    __                                                                          __ __       \n");
        printf(" |   _   |__.-----.-----.--.--.-----.-----|__.--|  .-----.   .---.-.   .--.--.-----.   .-----.--.--.-----.--.--.-----.   .--|  |__.---.-.\n");
        printf(" |. |_|  |  |  -__|     |  |  |  -__|     |  |  _  |  _  |   |  _  |   |  |  |     |   |     |  |  |  -__|  |  |  _  |   |  _  |  |  _  |\n");
        printf(" |.  _   |__|_____|__|__|\\ __/|_____|__|__|__|_____|_____|   |___._|   |_____|__|__|   |__|__|_____|_____|\\ __/|_____|   |_____|__|___._|\n");
        printf(" |: |_|   \\                                                                                                                              \n");
        printf(" |::.. .  /                                                                                                                              \n");
        printf(" `-------'                                                                                                                               \n");

    }
    else if (Num == 1)
    {
       
    }
    else if (Num == 2)
    {}
    else if (Num == 3)
    {}
    else if (Num == 4)
    {}
}

void AguaDisponible(int Num)
{
    if (Num == 0)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   A G U A   D I S P O N I B L E                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
    
    else if (Num == 1)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   A G U A   D I S P O N I B L E                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|       ____                                                                                                 |\n");
        printf("|      |____|                                                                                                |\n");
        printf("|       )  (                                                                                                 |\n");
        printf("|      /    \\                                                                                                |\n");
        printf("|     /      \\                                                                                               |\n");
        printf("|    |________|                                                                                              |\n");
        printf("|    |        |                                                                                              |\n");
        printf("|    |  AGUA  |                                                                                              |\n");
        printf("|    |________|                                                                                              |\n");
        printf("|    |        |                                                                                              |\n");
        printf("|    |        |                                                                                              |\n");
        printf("|    |________|                                                                                              |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
    
    else if (Num == 2)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   A G U A   D I S P O N I B L E                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|       ____              ____                                                                               |\n");
        printf("|      |____|            |____|                                                                              |\n");
        printf("|       )  (              )  (                                                                               |\n");
        printf("|      /    \\            /    \\                                                                              |\n");
        printf("|     /      \\          /      \\                                                                             |\n");
        printf("|    |________|        |________|                                                                            |\n");
        printf("|    |        |        |        |                                                                            |\n");
        printf("|    |  AGUA  |        |  AGUA  |                                                                            |\n");
        printf("|    |________|        |________|                                                                            |\n");
        printf("|    |        |        |        |                                                                            |\n");
        printf("|    |        |        |        |                                                                            |\n");
        printf("|    |________|        |________|                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
    
    else if (Num == 3)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   A G U A   D I S P O N I B L E                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|       ____              ____              ____                                                             |\n");
        printf("|      |____|            |____|            |____|                                                            |\n");
        printf("|       )  (              )  (              )  (                                                             |\n");
        printf("|      /    \\            /    \\            /    \\                                                            |\n");
        printf("|     /      \\          /      \\          /      \\                                                           |\n");
        printf("|    |________|        |________|        |________|                                                          |\n");
        printf("|    |        |        |        |        |        |                                                          |\n");
        printf("|    |  AGUA  |        |  AGUA  |        |  AGUA  |                                                          |\n");
        printf("|    |________|        |________|        |________|                                                          |\n");
        printf("|    |        |        |        |        |        |                                                          |\n");
        printf("|    |        |        |        |        |        |                                                          |\n");
        printf("|    |________|        |________|        |________|                                                          |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
    
    else if (Num == 4)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   A G U A   D I S P O N I B L E                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|       ____              ____              ____              ____                                           |\n");
        printf("|      |____|            |____|            |____|            |____|                                          |\n");
        printf("|       )  (              )  (              )  (              )  (                                           |\n");
        printf("|      /    \\            /    \\            /    \\            /    \\                                          |\n");
        printf("|     /      \\          /      \\          /      \\          /      \\                                         |\n");
        printf("|    |________|        |________|        |________|        |________|                                        |\n");
        printf("|    |        |        |        |        |        |        |        |                                        |\n");
        printf("|    |  AGUA  |        |  AGUA  |        |  AGUA  |        |  AGUA  |                                        |\n");
        printf("|    |________|        |________|        |________|        |________|                                        |\n");
        printf("|    |        |        |        |        |        |        |        |                                        |\n");
        printf("|    |        |        |        |        |        |        |        |                                        |\n");
        printf("|    |________|        |________|        |________|        |________|                                        |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
    else if (Num == 5)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   A G U A   D I S P O N I B L E                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|       ____              ____              ____              ____              ____                         |\n");
        printf("|      |____|            |____|            |____|            |____|            |____|                        |\n");
        printf("|       )  (              )  (              )  (              )  (              )  (                         |\n");
        printf("|      /    \\            /    \\            /    \\            /    \\            /    \\                        |\n");
        printf("|     /      \\          /      \\          /      \\          /      \\          /      \\                       |\n");
        printf("|    |________|        |________|        |________|        |________|        |________|                      |\n");
        printf("|    |        |        |        |        |        |        |        |        |        |                      |\n");
        printf("|    |  AGUA  |        |  AGUA  |        |  AGUA  |        |  AGUA  |        |  AGUA  |                      |\n");
        printf("|    |________|        |________|        |________|        |________|        |________|                      |\n");
        printf("|    |        |        |        |        |        |        |        |        |        |                      |\n");
        printf("|    |        |        |        |        |        |        |        |        |        |                      |\n");
        printf("|    |________|        |________|        |________|        |________|        |________|                      |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
    else if (Num == 6)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   A G U A   D I S P O N I B L E                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|       ____              ____              ____              ____              ____              ____       |\n");
        printf("|      |____|            |____|            |____|            |____|            |____|            |____|      |\n");
        printf("|       )  (              )  (              )  (              )  (              )  (              )  (       |\n");
        printf("|      /    \\            /    \\            /    \\            /    \\            /    \\            /    \\      |\n");
        printf("|     /      \\          /      \\          /      \\          /      \\          /      \\          /      \\     |\n");
        printf("|    |________|        |________|        |________|        |________|        |________|        |________|    |\n");
        printf("|    |        |        |        |        |        |        |        |        |        |        |        |    |\n");
        printf("|    |  AGUA  |        |  AGUA  |        |  AGUA  |        |  AGUA  |        |  AGUA  |        |  AGUA  |    |\n");
        printf("|    |________|        |________|        |________|        |________|        |________|        |________|    |\n");
        printf("|    |        |        |        |        |        |        |        |        |        |        |        |    |\n");
        printf("|    |        |        |        |        |        |        |        |        |        |        |        |    |\n");
        printf("|    |________|        |________|        |________|        |________|        |________|        |________|    |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
  
}

void ComidaDisponible(int Num)
{
    if (Num == 0)
    {
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   C O M I D A   D I S P O N I B L E                                                                        |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }                                                                                                                       
    else if (Num == 1)                                                                                                      
    {                                                                                                                       
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   C O M I D A   D I S P O N I B L E                                                                        |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|    _________                                                                                               |\n");
        printf("|   |_________|                                                                                              |\n");
        printf("|   |         |                                                                                              |\n");
        printf("|   |_^_^_^_^_|                                                                                              |\n");
        printf("|   |   _,_   |                                                                                              |\n");
        printf("|   |  |   |  |                                                                                              |\n");
        printf("|   |  |___|  |                                                                                              |\n");
        printf("|   |_________|                                                                                              |\n");
        printf("|   |         |                                                                                              |\n");
        printf("|   |_________|                                                                                              |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }                                                                                                                       
    else if (Num == 2)                                                                                                      
    {                                                                                                                       
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   C O M I D A   D I S P O N I B L E                                                                        |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|    _________         _________                                                                             |\n");
        printf("|   |_________|       |_________|                                                                            |\n");
        printf("|   |         |       |         |                                                                            |\n");
        printf("|   |_^_^_^_^_|       |_^_^_^_^_|                                                                            |\n");
        printf("|   |   _,_   |       |   _,_   |                                                                            |\n");
        printf("|   |  |   |  |       |  |   |  |                                                                            |\n");
        printf("|   |  |___|  |       |  |___|  |                                                                            |\n");
        printf("|   |_________|       |_________|                                                                            |\n");
        printf("|   |         |       |         |                                                                            |\n");
        printf("|   |_________|       |_________|                                                                            |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }                                                                                                                       
    else if (Num == 3)                                                                                                      
    {                                                                                                                       
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   C O M I D A   D I S P O N I B L E                                                                        |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|    _________         _________         _________                                                           |\n");
        printf("|   |_________|       |_________|       |_________|                                                          |\n");
        printf("|   |         |       |         |       |         |                                                          |\n");
        printf("|   |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|                                                          |\n");
        printf("|   |   _,_   |       |   _,_   |       |   _,_   |                                                          |\n");
        printf("|   |  |   |  |       |  |   |  |       |  |   |  |                                                          |\n");
        printf("|   |  |___|  |       |  |___|  |       |  |___|  |                                                          |\n");
        printf("|   |_________|       |_________|       |_________|                                                          |\n");
        printf("|   |         |       |         |       |         |                                                          |\n");
        printf("|   |_________|       |_________|       |_________|                                                          |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }                                                                                                                       
    else if (Num == 4)                                                                                                      
    {                                                                                                                       
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   C O M I D A   D I S P O N I B L E                                                                        |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|    _________         _________         _________         _________                                         |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|                                        |\n");
        printf("|   |         |       |         |       |         |       |         |                                        |\n");
        printf("|   |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|                                        |\n");
        printf("|   |   _,_   |       |   _,_   |       |   _,_   |       |   _,_   |                                        |\n");
        printf("|   |  |   |  |       |  |   |  |       |  |   |  |       |  |   |  |                                        |\n");
        printf("|   |  |___|  |       |  |___|  |       |  |___|  |       |  |___|  |                                        |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|                                        |\n");
        printf("|   |         |       |         |       |         |       |         |                                        |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|                                        |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }                                                                                                                       
    else if (Num == 5)                                                                                                      
    {                                                                                                                       
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   C O M I D A   D I S P O N I B L E                                                                        |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|    _________         _________         _________         _________         _________                       |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|       |_________|                      |\n");
        printf("|   |         |       |         |       |         |       |         |       |         |                      |\n");
        printf("|   |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|                      |\n");
        printf("|   |   _,_   |       |   _,_   |       |   _,_   |       |   _,_   |       |   _,_   |                      |\n");
        printf("|   |  |   |  |       |  |   |  |       |  |   |  |       |  |   |  |       |  |   |  |                      |\n");
        printf("|   |  |___|  |       |  |___|  |       |  |___|  |       |  |___|  |       |  |___|  |                      |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|       |_________|                      |\n");
        printf("|   |         |       |         |       |         |       |         |       |         |                      |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|       |_________|                      |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }                                                                                                                       
    else if (Num == 6)                                                                                                      
    {                                                                                                                       
        printf("\n ------------------------------------------------------------------------------------------------------------\n");
        printf("|   C O M I D A   D I S P O N I B L E                                                                        |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
        printf("|    _________         _________         _________         _________         _________         _________     |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|       |_________|       |_________|    |\n");
        printf("|   |         |       |         |       |         |       |         |       |         |       |         |    |\n");
        printf("|   |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|       |_^_^_^_^_|    |\n");
        printf("|   |   _,_   |       |   _,_   |       |   _,_   |       |   _,_   |       |   _,_   |       |   _,_   |    |\n");
        printf("|   |  |   |  |       |  |   |  |       |  |   |  |       |  |   |  |       |  |   |  |       |  |   |  |    |\n");
        printf("|   |  |___|  |       |  |___|  |       |  |___|  |       |  |___|  |       |  |___|  |       |  |___|  |    |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|       |_________|       |_________|    |\n");
        printf("|   |         |       |         |       |         |       |         |       |         |       |         |    |\n");
        printf("|   |_________|       |_________|       |_________|       |_________|       |_________|       |_________|    |\n");
        printf("|                                                                                                            |\n");
        printf(" ------------------------------------------------------------------------------------------------------------\n");
    }
    printf("\n\n");
    Continuar();
}

void DibujosSumarRestar(int Num)
{
    if (Num == 0)
    {
        printf("          _   _  _  ___    _____                 __              \n");
        printf("         ( ) ( )(_)(  _`\\ (  _  )              /'__`\\          \n");
        printf("         | | | || || | ) || (_) |       ______(_)  ) )           \n");
        printf("         | | | || || | | )|  _  |      (______)  /' /            \n");
        printf("         | \\_/ || || |_) || | | |              /' /__            \n");
        printf("          \\___/'(_)(____/'(_) (_)             (_____/'          \n\n\n");  
    }
    if (Num == 1)
    {
        printf("          _   _  _  ___    _____                 ___            \n");
        printf("         ( ) ( )(_)(  _`\\ (  _  )              /'_  )          \n");
        printf("         | | | || || | ) || (_) |       ______(_)_) |           \n");
        printf("         | | | || || | | )|  _  |      (______)_(_ <            \n");
        printf("         | \\_/ || || |_) || | | |             ( )_) |           \n");
        printf("         `\\___/'(_)(____/'(_) (_)             `\\____)         \n\n\n");  
    }
    if (Num == 2)
    {
        printf("          _____  ___    _   _  _____        _      _            \n");
        printf("         (  _  )(  _`\\ ( ) ( )(  _  )     ( )   /' )           \n");
        printf("         | (_) || ( (_)| | | || (_) |    __| |__(_, |           \n");
        printf("         |  _  || |___ | | | ||  _  |   (__   __) | |           \n");
        printf("         | | | || (_, )| (_) || | | |      | |    | |           \n");
        printf("         (_) (_)(____/'(_____)(_) (_)      (_)    (_)           \n\n\n");
    }
    if (Num == 3)
    {
        printf("         ___    _____         _  ___    _____              _       \n");
        printf("        (  _`\\ (  _  )/'\\_/`\\(_)(  _`\\ (  _  )           /' )      \n");
        printf("        | ( (_)| ( ) ||     || || | ) || (_) |    ______(_, |      \n");
        printf("        | |  _ | | | || (_) || || | | )|  _  |   (______) | |      \n");
        printf("        | (_( )| (_) || | | || || |_) || | | |            | |      \n");
        printf("        (____/'(_____)(_) (_)(_)(____/'(_) (_)            (_)      \n\n\n");
    }
    if (Num == 4)
    {
        printf("         ___    _____         _  ___    _____        _      _      \n");
        printf("        (  _`\\ (  _  )/'\\_/`\\(_)(  _`\\ (  _  )      ( )   /' )     \n");
        printf("        | ( (_)| ( ) ||     || || | ) || (_) |    __| |__(_, |     \n");
        printf("        | |  _ | | | || (_) || || | | )|  _  |   (__   __) | |     \n");
        printf("        | (_( )| (_) || | | || || |_) || | | |      | |    | |     \n");
        printf("        (____/'(_____)(_) (_)(_)(____/'(_) (_)      (_)    (_)     \n\n\n");
    }
}

void Final()
{
    printf(" _____________________________________________________________________________________________________________\n");
    printf("|                                                                                                             |\n");
    printf("|                                                                                                             |\n");
    printf("|       ESPERA! ACASO ESO QUE SE OYE SON LAS HELICES DE UN HELICOPTERO? CADA VEZ SE ESCUCHA MAS FUERTE!       |\n");
    printf("|                                                                                                             |\n");
    printf("|       SERA PORQUE SE ESTARA ACERCANDO? VIENEN A RESCATARTE? QUIZA DEBERIAS SALIR A COMPROBARLO.             |\n");
    printf("|                                                                                                             |\n");
    printf("|                                                                                                             |\n");
    printf("|                               .      .                                     .      .                         |\n");
    printf("|                             #@#      #@@.                                #@#      #@@.                      |\n");
    printf("|                          .#@@@#    :   =@@:                           .#@@@#    :   =@@:                    |\n");
    printf("|                        -@@@@@@#   .#@@.  +@#                        -@@@@@@#   .#@@.  +@#                   |\n");
    printf("|                      #@@@@@@@@#  -   *@#  .@#                     #@@@@@@@@#  -   *@#  .@#                  |\n");
    printf("|              -#####@@@@@@@@@@@# .#@#   #@. .@#            -#####@@@@@@@@@@@# .#@#   #@. .@#                 |\n");
    printf("|              *@@@@@@@@@@@@@@@@#    #@:  @#  *@-           *@@@@@@@@@@@@@@@@#    #@:  @#  *@-                |\n");
    printf("|              *@@@@@@@@@@@@@@@@@@-   #@  +@: :@*           *@@@@@@@@@@@@@@@@@@-   #@  +@: :@*                |\n");
    printf("|              *@@@@@@@@@@@@@@@@@@@   =@- :@= .@*           *@@@@@@@@@@@@@@@@@@@   =@- :@= .@*                |\n");
    printf("|              *@@@@@@@@@@@@@@@@@@-   #@  +@: :@*           *@@@@@@@@@@@@@@@@@@-   #@  +@: :@*                |\n");
    printf("|              *@@@@@@@@@@@@@@@@#    #@-  @#  *@-           *@@@@@@@@@@@@@@@@#    #@-  @#  *@-                |\n");
    printf("|              =#####@@@@@@@@@@@#  *@#   #@.  @#            =#####@@@@@@@@@@@#  *@#   #@.  @#                 |\n");
    printf("|                      #@@@@@@@@#  =   +@@  .@#                     #@@@@@@@@#  =   +@@  .@#                  |\n");
    printf("|                        =@@@@@@#    #@@:  =@#                        =@@@@@@#    #@@:  =@#                   |\n");
    printf("|                          :#@@@#    :   =@@:                           :#@@@#    :   =@@:                    |\n");
    printf("|                             #@#      #@@.                                #@#      #@@.                      |\n");
    printf("|                               .                                                                             |\n");
    printf("|                                                                                                             |\n");
    printf("|_____________________________________________________________________________________________________________|\n\n\n");
    
    printf("     __         ___  _           ___            _  __ ___ ___  __       _    _     \n");
    printf("    (_   /\\  |   |  |_)    /\\     |  |\\ | \\  / |_ (_   |   |  /__  /\\  |_)    )    \n");
    printf("    __) /--\\ |_ _|_ | \\   /--\\   _|_ | \\|  \\/  |_ __)  |  _|_ \\_| /--\\ | \\   o     \n\n\n");

    printf("                  -----\n");
    printf("         ---->    1. SI\n");
    printf("                  -----\n");
    printf("                  -----\n");
    printf("         ---->    2. NO\n");
    printf("                  -----\n\n");
    
    do
    {
        scanf("%d",&RespuestaFinal);
    }
    while (RespuestaFinal!=1 && RespuestaFinal!=2);
    getchar();
    system("cls");
    if (RespuestaFinal == 1)
    {
        printf(" _____________________________________________________________________________________________________________\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|       COGES LA MASCARA ANTIGAS Y SALES DEL BUNKER CON MUCHA ESPERANZA. AHI ESTA! UN HELICOPTERO!            |\n");
        printf("|                                                                                                             |\n");
        printf("|       EL OBJETO VOLADOR VA ACERCANDOSE LENTAMENTE A LA SUPERFICIE HASTA LOGRAR ATERRIZAR. DE EL SALEN       |\n");
        printf("|                                                                                                             |\n");
        printf("|       VARIAS PERSONAS QUE RAPIDAMENTE SE ACERCAN A TI Y TE OFRECEN UN LUGAR EN SU VEHICULO.                 |\n");
        printf("|                                                                                                             |\n");
        printf("|       SEGUN DICEN, TE LLEVARAN A UNA GRAN CIUDAD SUBTERRANEA DONDE SE ENCUENTRAN MUCHOS SUPERVIVIENTES.     |\n");
        printf("|                                                                                                             |\n");
        printf("|       DESPUES DE TANTOS DIAS, POR FIN DEJARAS DE ESTAR SOLO! VALIO LA PENA EL ESFUERZO POR SEGUIR ADELANTE! |\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|            .=*#@@@@@@@@@@@@@@@@@@@##*++-:.  =#@@@#=  .:-+**##@@@@@@@@@@@@@@@@@@@##=                         |\n");
        printf("|          .#@#-:.                ..::-=+#@#@@@-...-@@@@@#*=-::...               .:=#@@                       |\n");
        printf("|          =#+                              @#       #@                              *@=                      |\n");
        printf("|           #@@@*-.            .::=+##@@@@@@@@@@+=*@@@@@@@@@@##+=::.            .-*@@@#                       |\n");
        printf("|              :*#@@@@@@@@@@@@@@@###*=:       #@###@@       :=*###@@@@@@@@@@@@@@@#*:                          |\n");
        printf("|                                             #@  .@@                                                         |\n");
        printf("|                                             #@  .@@                               =@@@@@@@@@#:              |\n");
        printf("|                                      .-+*#@@@@@@@@@@#+-.                        #@#=       .*@@=            |\n");
        printf("|                                 :*@@@@#@@=:.      .:-=#@@@=                   :@@:    .::.    +@#           |\n");
        printf("|                              -#@@*:    -@#               -@@#:           .-*##@@@@@@@@@@@@@@#  -@#          |\n");
        printf("|                            #@@=         @@                  *@@###@@@@@@@@#*-..       #@@+  #@- #@-         |\n");
        printf("|                          #@@.           @@:                                          #@.+@: :@# =@=         |\n");
        printf("|                        :@@:             @@   #@@@@@@@.#@@@#.                         :@@@# .@@: #@-         |\n");
        printf("|                       +@#              +@= =@#     #@.#@- *@@@                          .+@@#  :##          |\n");
        printf("|                      =@#              +@#  @@      #@.#@-    @*                    .-#@@@#:   =##           |\n");
        printf("|                      @#              @#+   #@=     #@.#@- .+@@-               :+@@@@*=      =@#=            |\n");
        printf("|                     #@-            #@#.     =@@@@@@@@.#@@@@#-            :*@@@@*-.+@@@@@@@@##-              |\n");
        printf("|                     @@          =@@@.           ....                  *@@@*:          ...                   |\n");
        printf("|                    .@@@@#####@@@@-                                  +@@:                                    |\n");
        printf("|                     @@  .:-:                                      .@@=                                      |\n");
        printf("|                     #@-                                          #@#                                        |\n");
        printf("|                      @@                                        :@@:                                         |\n");
        printf("|                      :@@.                                    .#@*                                           |\n");
        printf("|                        #@#:                                .#@#                                             |\n");
        printf("|                         .*@@#=                        .-+#@@#.                                              |\n");
        printf("|                             -#@@@@@@@@@@@@@@@@@@@@@@@@@@#@=                                                 |\n");
        printf("|                                   .@#                   *@-                                                 |\n");
        printf("|                     @#             @#                   *@-           ##                                    |\n");
        printf("|                     -@#            @#                   *@-         .##:                                    |\n");
        printf("|                      .@@#.         @#                   *@-       .#@#                                      |\n");
        printf("|                        .#@@@@@@@@@@@@#@@@##@@@@@@@@@@@@@@@@@@@@@@@#*.                                       |\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|                      __       _   __  _        _   _     __  _   _   _   _     ___    ___  _                |\n");
        printf("|            |_|  /\\  (_    |  / \\ /__ |_)  /\\  | \\ / \\   (_  / \\ |_) |_) |_ \\  / | \\  / |  |_)               |\n");
        printf("|            | | /--\\ __)   |_ \\_/ \\_| | \\ /--\\ |_/ \\_/   __) \\_/ |_) | \\ |_  \\/ _|_ \\/ _|_ | \\               |\n");
        printf("|                                                                                                             |\n");
        printf("|_____________________________________________________________________________________________________________|\n\n\n");
    }
    else if (RespuestaFinal == 2)
    {
        printf(" _____________________________________________________________________________________________________________\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|        DESGRACIADAMENTE, PERDISTE LA OPORTUNIDAD DE TU VIDA. AQUELLO QUE ESCUCHASTE ERA CLARAMENTE UN       |\n");
        printf("|                                                                                                             |\n");
        printf("|        HELICOPTERO, PERO AL NO VER A NADIE EN LA SUPERFICIE, MARCHO EN BUSCA DE SUPERVIVIENTES EN OTRA      |\n");
        printf("|                                                                                                             |\n");
        printf("|        PARTE.                                                                                               |\n");
        printf("|                                                                                                             |\n");
        printf("|        LOS DIAS PASARON Y TU SEGUIAS LUCHANDO POR SOBREVIVIR, PERO LAS PROVISIONES ERAN CADA VEZ MAS        |\n");
        printf("|                                                                                                             |\n");
        printf("|        ESCASAS, ASI COMO LAS FUERZAS POR CONSEGUIRLAS.                                                      |\n");
        printf("|                                                                                                             |\n");
        printf("|        LLEGO UN MOMENTO EN EL QUE NO PUDISTE MAS Y, AHORA, TU CUERPO SIN VIDA YACE EN AQUEL BUNKER QUE      |\n");
        printf("|                                                                                                             |\n");
        printf("|        UNA VEZ FUE TU CASA Y QUE TUVISTE LA OPORTUNIDAD DE ABANDONAR EN BUSCA DE UNA VIDA MEJOR.            |\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|                                              .+@@@@@@@@@@@@@#:                                              |\n");
        printf("|                                            =@@@@@@@@@@@@@@@@@@@@-                                           |\n");
        printf("|                                          .@@@@@@@@@@@@@@@@@@@@@@@@.                                         |\n");
        printf("|                                         =@@@@@@@@@@@@@@@@@@@@@@@@@@+                                        |\n");
        printf("|                                        +@@@@@@@@@@@@@@@@@@@@@@@@@@@@*                                       |\n");
        printf("|                                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                       |\n");
        printf("|                                       +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+                                      |\n");
        printf("|                                       *@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*                                      |\n");
        printf("|                                       +@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@=                                      |\n");
        printf("|                                        @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@                                       |\n");
        printf("|                                        #@@@@#-     -@@@@-     .*@@@@#                                       |\n");
        printf("|                                         @@@#        *@@#        *@@#                                        |\n");
        printf("|                                         .@@*        #@@@:       +@@.                                        |\n");
        printf("|                                          #@@*-:::=*@@*#@@#=-:.-*@@#                                         |\n");
        printf("|                                         -@@@@@@@@@@@+  *@@@@@@@@@@@-                                        |\n");
        printf("|                                         #@@@@@@@@@@@    @@@@@@@@@@@#                                        |\n");
        printf("|                                          :---=#@@@@@@@@@@@@@@*=---:                                         |\n");
        printf("|                                     .+#=       *@@@@@@@@@@@@*        #@#.                                   |\n");
        printf("|                                     #@@@#.    :#@@@@@@@@@@@@#:     :@@@@#                                   |\n");
        printf("|                                    -@@@@@@-    *#@@@@@@@@@@#*.    +@@@@@#.                                  |\n");
        printf("|                                   *@@@@@@@@*                    +@@@@@@@@@*                                 |\n");
        printf("|                                  *@@@@@@@@@@@#=              :#@@@@@@@@@@@@=                                |\n");
        printf("|                                  -*#*****##@@@@@@*:       -#@@@@@#*+=++***-                                 |\n");
        printf("|                                              =##@@@@@=.+@@@@@#+                                             |\n");
        printf("|                                                  -#@@@@@@@#.                                                |\n");
        printf("|                                               .*@@@@@@#@@@@@@#:                                             |\n");
        printf("|                                   :##=    +@@@@@@@#=     =#@@@@@@@@#++#@@@#                                 |\n");
        printf("|                                   #@@@@@@@@@@@@#:           .#@@@@@@@@@@@@#:                                |\n");
        printf("|                                   -#@@@@@@@@#:                  *@@@@@@@@@+                                 |\n");
        printf("|                                     #@@@@@#                       +@@@@@*                                   |\n");
        printf("|                                     #@@@@#                         *@@@@.                                   |\n");
        printf("|                                      #@@#                           +@@.                                    |\n");
        printf("|                                                                                                             |\n");
        printf("|                                                                                                             |\n");
        printf("|              _              __       _   __  _        _   _     __  _   _   _   _     ___    ___  _         |\n");
        printf("|        |\\ | / \\   |_|  /\\  (_    |  / \\ /__ |_)  /\\  | \\ / \\   (_  / \\ |_) |_) |_ \\  / | \\  / |  |_)        |\n");
        printf("|        | \\| \\_/   | | /--\\ __)   |_ \\_/ \\_| | \\ /--\\ |_/ \\_/   __) \\_/ |_) | \\ |_  \\/ _|_ \\/ _|_ | \\        |\n");
        printf("|                                                                                                             |\n");
        printf("|_____________________________________________________________________________________________________________|\n\n\n");
    } 
}