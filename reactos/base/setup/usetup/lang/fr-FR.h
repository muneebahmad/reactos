#ifndef LANG_FR_FR_H__
#define LANG_FR_FR_H__

static MUI_ENTRY frFRLanguagePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "S�lection de la langue.",
        TEXT_NORMAL
    },
    {
        8,
        10,
        "\x07  Veuiller choisir la langue utilis�e pour le processus d'installation",
        TEXT_NORMAL
    },
    {
        8,
        11,
        "   et appuyer sur ENTER.",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "\x07  Cette langue sera la langue par d�faut pour le syst�me final.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer  F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRWelcomePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Bienvenue � l'installation de ReactOS",
        TEXT_HIGHLIGHT
    },
    {
        6,
        11,
        "Cette partie de l'installation copie le Syst�me d'Exploitation ReactOS",
        TEXT_NORMAL
    },
    {
        6,
        12,
        "sur votre ordinateur et le pr�pare � la 2e partie de l'installation.",
        TEXT_NORMAL
    },
    {
        8,
        15,
        "\x07  Appuyer sur ENTER pour installer ReactOS.",
        TEXT_NORMAL
    },
    {
        8,
        17,
        "\x07  Appuyer sur R pour r�parer ReactOS.",
        TEXT_NORMAL
    },
    {
        8,
        19,
        "\x07  Appuyer sur L pour les Termes et Conditions de Licence ReactOS",
        TEXT_NORMAL
    },
    {
        8,
        21,
        "\x07  Appuyer sur F3 pour quitter sans installer ReactOS.",
        TEXT_NORMAL
    },
    {
        6,
        23,
        "Pour plus d'informations sur ReactOS, veuiller visiter :",
        TEXT_NORMAL
    },
    {
        6,
        24,
        "http://www.reactos.org",
        TEXT_HIGHLIGHT
    },
    {
        0,
        0,
        "   ENTER = Continuer  R = R�parer F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRIntroPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "L'Installation de ReactOS est en phase de d�veloppement.",
        TEXT_NORMAL
    },
    {
        6,
        9,
        "Elle ne supporte pas encore toutes les fonctions d'une application",
        TEXT_NORMAL
    },
    {
        6,
        10,
        " d'installation enti�rement utilisable.",
        TEXT_NORMAL
    },
    {
        6,
        12,
        "Les limitations suivantes s'appliquent:",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "- L'installation ne peut g�rer plus d'une partition primaire par disque.",
        TEXT_NORMAL
    },
    {
        8,
        14,
        "- L'installation ne peut effacer une partition primaire d'un disque",
        TEXT_NORMAL
    },
    {
        8,
        15,
        "  tant que des partitions secondaires existent sur ce disque.",
        TEXT_NORMAL
    },
    {
        8,
        16,
        "- L'installation ne peut effacer la premi�re partition secondaire",
        TEXT_NORMAL
    },
    {
        8,
        17,
        "  tant que des autres partitions secondaires existent sur ce disque.",
        TEXT_NORMAL
    },
    {
        8,
        18,
        "- L'installation supporte uniquement le syst�me de fichiers FAT.",
        TEXT_NORMAL
    },
    {
        8,
        19,
        "- Les v�rifications de syst�me de fichers ne sont pas impl�ment�es.",
        TEXT_NORMAL
    },
    {
        8,
        23,
        "\x07  Appuyer sur ENTER pour installer ReactOS.",
        TEXT_NORMAL
    },
    {
        8,
        25,
        "\x07  Appuyer sur F3 pour quitter sans installer ReactOS.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRLicensePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        6,
        "Licence :",
        TEXT_HIGHLIGHT
    },
    {
        8,
        8,
        "The ReactOS System is licensed under the terms of the",
        TEXT_NORMAL
    },
    {
        8,
        9,
        "GNU GPL with parts containing code from other compatible",
        TEXT_NORMAL
    },
    {
        8,
        10,
        "licenses such as the X11 or BSD and GNU LGPL licenses.",
        TEXT_NORMAL
    },
    {
        8,
        11,
        "All software that is part of the ReactOS system is",
        TEXT_NORMAL
    },
    {
        8,
        12,
        "therefore released under the GNU GPL as well as maintaining",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "the original license.",
        TEXT_NORMAL
    },
    {
        8,
        15,
        "This software comes with NO WARRANTY or restrictions on usage",
        TEXT_NORMAL
    },
    {
        8,
        16,
        "save applicable local and international law. The licensing of",
        TEXT_NORMAL
    },
    {
        8,
        17,
        "ReactOS only covers distribution to third parties.",
        TEXT_NORMAL
    },
    {
        8,
        18,
        "If for some reason you did not receive a copy of the",
        TEXT_NORMAL
    },
    {
        8,
        19,
        "GNU General Public License with ReactOS please visit",
        TEXT_NORMAL
    },
    {
        8,
        20,
        "http://www.gnu.org/licenses/licenses.html",
        TEXT_HIGHLIGHT
    },
    {
        8,
        22,
        "Garantie :",
        TEXT_HIGHLIGHT
    },
    {
        8,
        24,
        "This is free software; see the source for copying conditions.",
        TEXT_NORMAL
    },
    {
        8,
        25,
        "There is NO warranty; not even for MERCHANTABILITY or",
        TEXT_NORMAL
    },
    {
        8,
        26,
        "FITNESS FOR A PARTICULAR PURPOSE",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Retour",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRDevicePageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "La liste ci-dessous montre les r�glages mat�riels actuels.",
        TEXT_NORMAL
    },
    {
        8,
        11,
        "     Ordinateur :",
        TEXT_NORMAL
    },
    {
        8,
        12,
        "      Affichage :",
        TEXT_NORMAL,
    },
    {
        8,
        13,
        "        Clavier :",
        TEXT_NORMAL
    },
    {
        8,
        14,
        "R�glage Clavier :",
        TEXT_NORMAL
    },
    {
        8,
        16,
        "       Accepter :",
        TEXT_NORMAL
    },
    {
        25,
        16, "Accepter ces r�glages mat�riels",
        TEXT_NORMAL
    },
    {
        6,
        19,
        "Vous pouvez changer les r�glages mat�riels en appuyant sur HAUT ou BAS",
        TEXT_NORMAL
    },
    {
        6,
        20,
        "pour s�lectionner une entr�e.",
        TEXT_NORMAL
    },
    {
        6,
        21,
        "Appuyer sur ENTER pour choisir un autre r�glage.",
        TEXT_NORMAL
    },
    {
        6,
        23,
        "Quand tous les r�glages sont corrects, s�lectionner \"Accepter",
        TEXT_NORMAL
    },
    {
        6,
        24,
        "ces r�glages mat�riels\" et appuyer sur ENTER.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRRepairPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "L'Installation de ReactOS est en phase de d�veloppement.",
        TEXT_NORMAL
    },
    {
        6,
        9,
        "Elle ne supporte pas encore toutes les fonctions d'une application",
        TEXT_NORMAL
    },
    {
        6,
        10,
        "d'installation enti�rement utilisable.",
        TEXT_NORMAL
    },
    {
        6,
        12,
        "Les fonctions de r�paration ne sont pas impl�ment�es pour l'instant.",
        TEXT_NORMAL
    },
    {
        8,
        15,
        "\x07  Appuyer sur U pour mettre � jour l'OS.",
        TEXT_NORMAL
    },
    {
        8,
        17,
        "\x07  Appuyer sur R pour la Console de R�paration.",
        TEXT_NORMAL
    },
    {
        8,
        19,
        "\x07  Appuyer sur ESC pour retourner � la page principale.",
        TEXT_NORMAL
    },
    {
        8,
        21,
        "\x07  Appuyer sur ENTER pour red�marrer votre ordinateur.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ESC = Page principale  ENTER = Red�marrer",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};
static MUI_ENTRY frFRComputerPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Vous voulez changer le type d'ordinateur install�.",
        TEXT_NORMAL
    },
    {
        8,
        10,
        "\x07  Appuyer sur HAUT ou BAS pour s�lectionner le type d'ordinateur.",
        TEXT_NORMAL
    },
    {
        8,
        11,
        "   Puis appuyer sur ENTER.",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyer sur ESC pour revenir � la page pr�c�dente sans changer",
        TEXT_NORMAL
    },
    {
        8,
        14,
        "   le type d'ordinateur.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   ESC = Annuler   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRFlushPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        10,
        6,
        "Le syst�me s'assure que toutes les donn�es sont �crites sur le disque",
        TEXT_NORMAL
    },
    {
        10,
        8,
        "Cela peut prendre une minute",
        TEXT_NORMAL
    },
    {
        10,
        9,
        "Quand cela sera fini, votre ordinateur red�marrera automatiquement",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   Vidage du cache",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRQuitPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        10,
        6,
        "ReactOS n'est pas compl�tement install�",
        TEXT_NORMAL
    },
    {
        10,
        8,
        "Enlever la disquette du lecteur A: et",
        TEXT_NORMAL
    },
    {
        10,
        9,
        "tous les CDROMs des lecteurs de CD.",
        TEXT_NORMAL
    },
    {
        10,
        11,
        "Appuyer sur ENTER pour red�marrer votre ordinateur.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   Veuillez attendre ...",
        TEXT_STATUS,
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRDisplayPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Vous voulez changer le type d'�cran � installer.",
        TEXT_NORMAL
    },
    {   8,
        10,
         "\x07  Appuyer sur HAUT ou BAS pour s�lectionner le type d'�cran.",
         TEXT_NORMAL
    },
    {
        8,
        11,
        "   Appuyer sur ENTER.",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyer sur ESC pour revenir � la page pr�c�dente sans changer",
        TEXT_NORMAL
    },
    {
        8,
        14,
        "   le type d'�cran.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   ESC = Annuler   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRSuccessPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        10,
        6,
        "Les composants standards de ReactOS ont �t� install�s avec succ�s.",
        TEXT_NORMAL
    },
    {
        10,
        8,
        "Enlever la disquette du lecteur A: et",
        TEXT_NORMAL
    },
    {
        10,
        9,
        "tous les CDROMs des lecteurs de CD.",
        TEXT_NORMAL
    },
    {
        10,
        11,
        "Appuyer sur ENTER pour red�marrer votre ordinateur.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Red�marrer l'ordinateur",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRBootPageEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Setup ne peut installer le chargeur sur le disque dur",
        TEXT_NORMAL
    },
    {
        6,
        9,
        "de votre ordinateur",
        TEXT_NORMAL
    },
    {
        6,
        13,
        "Veuillez ins�rer une disquette format�e dans le lecteur A: et",
        TEXT_NORMAL
    },
    {
        6,
        14,
        "appuyer sur ENTER.",
        TEXT_NORMAL,
    },
    {
        0,
        0,
        "   ENTER = Continuer   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }

};

static MUI_ENTRY frFRSelectPartitionEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "La liste suivante montre les partitions existantes et",
        TEXT_NORMAL
    },
    {
        6,
        9,
        "l'espace disque non utilise pour de nouvelles partitions.",
        TEXT_NORMAL
    },
    {
        8,
        11,
        "\x07  Appuyer sur HAUT ou BAS pour s�lectionner une entree de la liste.",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyer sur ENTER pour installer ReactOS sur la partition choisie.",
        TEXT_NORMAL
    },
    {
        8,
        15,
        "\x07  Appuyer sur C pour creer une nouvelle partition.",
        TEXT_NORMAL
    },
    {
        8,
        17,
        "\x07  Appuyer sur D pour effacer une partition.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   Patienter...",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRFormatPartitionEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Formater la partition",
        TEXT_NORMAL
    },
    {
        6,
        10,
        "Setup va formater la partition. Appuyer sur ENTER pour continuer.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        TEXT_NORMAL
    }
};

static MUI_ENTRY frFRInstallDirectoryEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Setup installe les fichiers de ReactOS sur la partition s�lectionn�e.",
        TEXT_NORMAL
    },
    {
        6,
        9,
        "Choisissez un repertoire o� vous voulez que ReactOS soit install� :",
        TEXT_NORMAL
    },
    {
        6,
        14,
        "Pour changer le r�pertoire propos�, appuyez sur BACKSPACE pour effacer",
        TEXT_NORMAL
    },
    {
        6,
        15,
        "des caract�res et ensuite tapez le r�pertoire ou vous voulez que",
        TEXT_NORMAL
    },
    {
        6,
        16,
        "ReactOS soit install�",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRFileCopyEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        11,
        12,
        "Patientez pendant que ReactOS Setup copie les fichiers",
        TEXT_NORMAL
    },
    {
        15,
        13,
        "dans le r�pertoire d'installation de ReactOS.",
        TEXT_NORMAL
    },
    {
        20,
        14,
        "Cela peut prendre plusieurs minutes.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "                                                           \xB3 Patientez...    ",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRBootLoaderEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Setup installe le chargeur de d�marrage",
        TEXT_NORMAL
    },
    {
        8,
        12,
        "Installer le chargeur de d�marrage sur le disque dur (MBR).",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "Installer le chargeur de d�marrage sur une disquette.",
        TEXT_NORMAL
    },
    {
        8,
        14,
        "Ne pas installer le chargeur de d�marrage.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRKeyboardSettingsEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Vous voulez changer le type de clavier � installer.",
        TEXT_NORMAL
    },
    {
        8,
        10,
        "\x07  Appuyez sur HAUT ou BAS pour s�lectionner le type de clavier,",
        TEXT_NORMAL
    },
    {
        8,
        11,
        "   puis appuyez sur ENTER.",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyez sur ESC pour revenir a la page pr�c�dente sans changer",
        TEXT_NORMAL
    },
    {
        8,
        14,
        "   le type de clavier.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   ESC = Annuler   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRLayoutSettingsEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Vous voulez changer la disposition du clavier.",
        TEXT_NORMAL
    },
    {
        8,
        10,
        "\x07  Appuyez sur HAUT ou BAS pour s�lectionner la disposition",
        TEXT_NORMAL
    },
    {
        8,
        11,
        "    choisie. Puis appuyez sur ENTER.",
        TEXT_NORMAL
    },
    {
        8,
        13,
        "\x07  Appuyez sur ESC pour revenir a la page pr�c�dente sans changer",
        TEXT_NORMAL
    },
    {
        8,
        14,
        "   la disposition du clavier.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   ENTER = Continuer   ESC = Annuler   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY frFRPrepareCopyEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Setup pr�pare votre ordinateur pour copier les fichiers de ReactOS. ",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   Pr�pare la liste de fichiers � copier...",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    },

};

static MUI_ENTRY frFRSelectFSEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        17,
        "S�lectionnez un syst�me de fichiers dans la liste suivante.",
        0
    },
    {
        8,
        19,
        "\x07  Appuyez sur HAUT ou BAS pour s�lectionner un syst�me de fichiers.",
        0
    },
    {
        8,
        21,
        "\x07  Appuyez sur ENTER pour formater la partition.",
        0
    },
    {
        8,
        23,
        "\x07  Appuyez sur ESC pour s�lectionner une autre partition.",
        0
    },
    {
        0,
        0,
        "   ENTER = Continuer   ESC = Annuler   F3 = Quitter",
        TEXT_STATUS
    },

    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRDeletePartitionEntries[] =
{
    {
        4,
        3,
        " Installation de ReactOS " KERNEL_VERSION_STR " ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Vous avez choisi de supprimer la partition",
        TEXT_NORMAL
    },
    {
        8,
        18,
        "\x07  Appuyez sur D pour supprimer la partition.",
        TEXT_NORMAL
    },
    {
        11,
        19,
        "ATTENTION: Toutes les donne�es de cette partition seront perdues!",
        TEXT_NORMAL
    },
    {
        8,
        21,
        "\x07  Appuyez sur ESC pour annuler.",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   D = Supprimer la Partition   ESC = Annuler   F3 = Quitter",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    }
};

static MUI_ENTRY frFRRegistryEntries[] =
{
    {
        4,
        3,
        " ReactOS " KERNEL_VERSION_STR " Setup ",
        TEXT_UNDERLINE
    },
    {
        6,
        8,
        "Setup met � jour la configuration du syst�me. ",
        TEXT_NORMAL
    },
    {
        0,
        0,
        "   En train de cr�er la base de registres...",
        TEXT_STATUS
    },
    {
        0,
        0,
        NULL,
        0
    },

};

MUI_ERROR frFRErrorEntries[] =
{
    {
        //ERROR_NOT_INSTALLED
        "ReactOS n'est pas compl�tement install� sur votre\n"
        "ordinateur. Si vous quittez Setup maintenant, vous devrez\n"
        "lancer Setup de nouveau pour installer ReactOS.\n"
        "\n"
        "  \x07  Appuyer sur ENTER pour continuer Setup.\n"
        "  \x07  Appuyer sur F3 pour quitter Setup.",
        "F3= Quitter  ENTER = Continuer"
    },
    {
        //ERROR_NO_HDD
        "Setup n'a pu trouver un disque dur.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_NO_SOURCE_DRIVE
        "Setup n'a pu trouver son lecteur source.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_TXTSETUPSIF
        "Setup n'a pas r�ussi � charger le fichier TXTSETUP.SIF.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CORRUPT_TXTSETUPSIF
        "Setup a trouv� un fichier TXTSETUP.SIF corrompu.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_SIGNATURE_TXTSETUPSIF,
        "Setup a trouv� une signature invalide dans TXTSETUP.SIF.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_DRIVE_INFORMATION
        "Setup n'a pu r�cup�rer les informations du disque syst�me.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_WRITE_BOOT,
        "Echec de l'installation du code de d�marrage FAT sur la partition syst�me.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_COMPUTER,
        "Setup n'a pu charger la liste de type d'ordinateurs.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_DISPLAY,
        "Setup n'a pu charger la liste de r�glages des �crans.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_KEYBOARD,
        "Setup n'a pu charger la liste de types de claviers.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_LOAD_KBLAYOUT,
        "Setup n'a pu charger la liste de dispositions de claviers.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_WARN_PARTITION,
        "Setup a d�tect� qu'au moins un disque dur contient une table\n"
        "de partition incompatible qui ne peut �tre prise en compte!\n"
        "\n"
        "Cr�er ou effacer des partitions peut d�truire la table de partition.\n"
        "\n"
        "  \x07  Appuyer sur F3 pour quitter Setup."
        "  \x07  Appuyer sur ENTER pour continuer Setup.",
        "F3= Quitter  ENTER = Continuer"
    },
    {
        //ERROR_NEW_PARTITION,
        "Vous ne pouvez cr�er une nouvelle Partition � l'int�rieur\n"
        "d'une Partition d�j� existante!\n"
        "\n"
        "  * Appuyer sur une touche pour continuer.",
        NULL
    },
    {
        //ERROR_DELETE_SPACE,
        "Vous ne pouvez supprimer de l'espace disque non partitionn�!\n"
        "\n"
        "  * Appuyer sur une touche pour continuer.",
        NULL
    },
    {
        //ERROR_INSTALL_BOOTCODE,
        "Echec de l'installation du code de d�marrage FAT sur la partition syst�me.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_NO_FLOPPY,
        "Pas de disque dans le lecteur A:.",
        "ENTER = Continuer"
    },
    {
        //ERROR_UPDATE_KBSETTINGS,
        "Setup n'a pu mettre � jour les r�glages de disposition du clavier.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_UPDATE_DISPLAY_SETTINGS,
        "Setup n'a pu mettre � jour les r�glages de l'�cran.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_IMPORT_HIVE,
        "Setup n'a pu importer un fichier ruche.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_FIND_REGISTRY
        "Setup n'a pu trouver les fichiers de la base de registres.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CREATE_HIVE,
        "Setup n'a pu cr�er les ruches de la base de registres.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_INITIALIZE_REGISTRY,
        "Setup n'a pu initialiser la base de registres.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_INVALID_CABINET_INF,
        "Le Cabinet n'a pas de fichier inf valide.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CABINET_MISSING,
        "Cabinet non trouv�.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CABINET_SCRIPT,
        "Cabinet n'a pas de script de setup.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_COPY_QUEUE,
        "Setup n'a pu ouvrir la file d'attente de copie de fichiers.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CREATE_DIR,
        "Setup n'a pu cr�er les r�pertoires d'installation.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_TXTSETUP_SECTION,
        "Setup n'a pu trouver la section 'Directories'\n"
        "dans TXTSETUP.SIF.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CABINET_SECTION,
        "Setup n'a pu trouver la section 'Directories\n"
        "dans le cabinet.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_CREATE_INSTALL_DIR
        "Setup n'a pu cr�er le r�pertoire d'installation.",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_FIND_SETUPDATA,
        "Setup n'a pu trouver la section 'SetupData'\n"
        "dans TXTSETUP.SIF.\n",
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_WRITE_PTABLE,
        "Setup n'a pu �crire les tables de partition.\n"
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_ADDING_CODEPAGE,
        "Setup n'a pu ajouter la page de codes � la base de registres.\n"
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        //ERROR_UPDATE_LOCALESETTINGS,
        "Setup n'a pu changer la langue syst�me.\n"
        "ENTER = Red�marrer l'ordinateur"
    },
    {
        NULL,
        NULL
    }
};


MUI_PAGE frFRPages[] =
{
    {
        LANGUAGE_PAGE,
        frFRLanguagePageEntries
    },
    {
        START_PAGE,
        frFRWelcomePageEntries
    },
    {
        INSTALL_INTRO_PAGE,
        frFRIntroPageEntries
    },
    {
        LICENSE_PAGE,
        frFRLicensePageEntries
    },
    {
        DEVICE_SETTINGS_PAGE,
        frFRDevicePageEntries
    },
    {
        REPAIR_INTRO_PAGE,
        frFRRepairPageEntries
    },
    {
        COMPUTER_SETTINGS_PAGE,
        frFRComputerPageEntries
    },
    {
        DISPLAY_SETTINGS_PAGE,
        frFRDisplayPageEntries
    },
    {
        FLUSH_PAGE,
        frFRFlushPageEntries
    },
    {
        SELECT_PARTITION_PAGE,
        frFRSelectPartitionEntries
    },
    {
        SELECT_FILE_SYSTEM_PAGE,
        frFRSelectFSEntries
    },
    {
        FORMAT_PARTITION_PAGE,
        frFRFormatPartitionEntries
    },
    {
        DELETE_PARTITION_PAGE,
        frFRDeletePartitionEntries
    },
    {
        INSTALL_DIRECTORY_PAGE,
        frFRInstallDirectoryEntries
    },
    {
        PREPARE_COPY_PAGE,
        frFRPrepareCopyEntries
    },
    {
        FILE_COPY_PAGE,
        frFRFileCopyEntries
    },
    {
        KEYBOARD_SETTINGS_PAGE,
        frFRKeyboardSettingsEntries
    },
    {
        BOOT_LOADER_PAGE,
        frFRBootLoaderEntries
    },
    {
        LAYOUT_SETTINGS_PAGE,
        frFRLayoutSettingsEntries
    },
    {
        QUIT_PAGE,
        frFRQuitPageEntries
    },
    {
        SUCCESS_PAGE,
        frFRSuccessPageEntries
    },
    {
        BOOT_LOADER_FLOPPY_PAGE,
        frFRBootPageEntries
    },
    {
        REGISTRY_PAGE,
        frFRRegistryEntries
    },
    {
        -1,
        NULL
    }
};

MUI_STRING frFRStrings[] =
{
    {STRING_PLEASEWAIT,
     "   Veuillez patienter..."},
    {STRING_INSTALLCREATEPARTITION,
     "   ENTER = Installer   C = Cr�er Partition   F3 = Quitter"},
    {STRING_INSTALLDELETEPARTITION,
     "   ENTER = Installer   D = Supprimer Partition   F3 = Quitter"},
    {STRING_PARTITIONSIZE,
     "Taille de la nouvelle partition :"},
    {STRING_CHOOSENEWPARTITION,
     "Vous avez choisi de cr�er une nouvelle partition sur"},
    {STRING_HDDSIZE,
    "Please enter the size of the new partition in megabytes."},
    {STRING_CREATEPARTITION,
     "   ENTER = Cr�er Partition   ESC = Annuler   F3 = Quitter"},
    {STRING_PARTFORMAT,
    "This Partition will be formatted next."},
    {STRING_NONFORMATTEDPART,
    "You chose to install ReactOS on a new or unformatted Partition."},
    {STRING_INSTALLONPART,
    "Setup install ReactOS onto Partition"},
    {STRING_CHECKINGPART,
    "Setup is now checking the selected partition."},
    {STRING_QUITCONTINUE,
    "F3= Quit  ENTER = Continue"},
    {STRING_REBOOTCOMPUTER,
    "ENTER = Reboot computer"},
    {STRING_TXTSETUPFAILED,
    "Setup failed to find the '%S' section\nin TXTSETUP.SIF.\n"},
    {STRING_COPYING,
     "                                                   \xB3 Copie du fichier: %S"},
    {STRING_SETUPCOPYINGFILES,
     "Setup copie les fichiers..."},
    {STRING_PAGEDMEM,
     "M�moire pagin�e"},
    {STRING_NONPAGEDMEM,
     "M�moire non pagin�e"},
    {STRING_FREEMEM,
     "M�moire libre"},
    {STRING_REGHIVEUPDATE,
    "   Updating registry hives..."},
    {STRING_IMPORTFILE,
    "   Importing %S..."},
    {STRING_DISPLAYETTINGSUPDATE,
    "   Updating display registry settings..."},
    {STRING_LOCALESETTINGSUPDATE,
    "   Updating locale settings..."},
    {STRING_KEYBOARDSETTINGSUPDATE,
    "   Updating keyboard layout settings..."},
    {STRING_CODEPAGEINFOUPDATE,
    "   Adding codepage information to registry..."},
    {STRING_DONE,
    "   Done..."},
    {STRING_REBOOTCOMPUTER2,
    "   ENTER = Reboot computer"},
    {STRING_CONSOLEFAIL1,
    "Unable to open the console\n\n"},
    {STRING_CONSOLEFAIL2,
    "The most common cause of this is using an USB keyboard\n"},
    {STRING_CONSOLEFAIL3,
    "USB keyboards are not fully supported yet\n"},
    {STRING_FORMATTINGDISK,
    "Setup is formatting your disk"},
    {STRING_CHECKINGDISK,
    "Setup is checking your disk"},
    {STRING_FORMATDISK1,
    " Format partition as %S file system (quick format) "},
    {STRING_FORMATDISK2,
    " Format partition as %S file system "},
    {0, 0}
};

#endif
