#include <stdio.h>
#include <stdlib.h>
#include "collections/LinkedList.h"
#include "collections/Dictionary.h"
#include "Employee.h"
#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, Dictionary* pArrayListEmployee, int* idMaximo)
{
    Employee* pAuxEmpleado;
    char id[10];
    char nombre[128];
    char horasTrabajo[10];
    char sueldo[10];
    int retorno=-1;
    int idMax;


    if(pFile != NULL){
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajo,sueldo);
        idMax=atoi(id);
        while(!feof(pFile))
          {
            if(feof(pFile))
            {
                break;
            }

            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajo,sueldo);
            pAuxEmpleado = employee_newParametros(id,nombre,horasTrabajo,sueldo);
            if(pAuxEmpleado != NULL){
                dict_insert(pArrayListEmployee, id, pAuxEmpleado);
                if(atoi(id)>idMax)
                                idMax = atoi(id);
            }
        }
        fclose(pFile);
        retorno=0;
        *idMaximo = idMax;
    }

    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, Dictionary* pArrayListEmployee, int* idMaximo)
{
    Employee* pEmpleado=NULL;
    int retorno=-1;
    char id[10];
    int indice;
    int idMax;
    if(pFile != NULL){
        indice =0;
        do{
            pEmpleado=employee_new();
            if(pEmpleado != NULL){
                if(fread(pEmpleado,sizeof(Employee),1,pFile)==1){
                    employee_getIdText(pEmpleado,id);
                    dict_insert(pArrayListEmployee, id, pEmpleado);
                    if(indice==0)
                      idMax = atoi(id); // me guardo el 1ero como MAX
                    else if(atoi(id)>idMax)
                      {
                        idMax = atoi(id);
                      }
                    indice++;
                }
                else{employee_delete(pEmpleado);}
            }
        }while(feof(pFile)==0);
        retorno = 0;
        *idMaximo = idMax;
        fclose(pFile);
    }
    return retorno;
}
