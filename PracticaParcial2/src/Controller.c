#ifndef controller_H_INCLUDED
#define controller_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Controller.h"
#include "collections/LinkedList.h"


#define SIZE_NAME 128

static int contador=0; // NO ES LOCAL DE LA FUNCION
static int controller_printLinkedlistEmployee(LinkedList* pArrayListEmployee);

void emp_setearValorInicialDeId(int id)
{
  contador = id;
}

int emp_generarId(void)
{
  contador++;
  return contador;
}


int controller_loadFromText(char* path, Dictionary* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"r");

    if(pArchivoTexto == NULL)
    {
        retorno=-1;
        printf("\nError al cargar los datos del archivo.\n");
   /* }else if(ll_isEmpty(pArrayListEmployee) == 0){
        retorno=1;
        printf("\nYa cargo los datos del archivo anteriormente.\n"); TODO isempty dictionary? o similar*/
    }else{
        parser_EmployeeFromText(pArchivoTexto,pArrayListEmployee,&contador);
        retorno=0;
        printf("\nDatos cargados correctamente.\n");
    }

    return retorno;
}


int controller_loadFromBinary(char* path, Dictionary* pArrayListEmployee)
{
    FILE* pArchivoTexto;
    pArchivoTexto = fopen(path,"rb");
    int retorno;
    if(pArchivoTexto == NULL)
    {
        printf("\nERROR. El archivo no existe o esta dañado.\n");
        retorno=-1;
    /*}else if(ll_isEmpty(pArrayListEmployee) == 0){
        retorno=1;
        printf("\nYa cargo los datos del archivo anteriomente.\n"); TODO isempty dictionary? o similar*/
    }else{
        parser_EmployeeFromBinary(pArchivoTexto,pArrayListEmployee,&contador);
        printf("\nDatos cargados correctamente.\n");
        retorno=0;
    }
    return retorno;
}


int controller_addEmployee(Dictionary* pArrayListEmployee)
{
    char nombre[SIZE_NAME];
    int horasTrabajo;
    int sueldo;
    int nuevoId;
    Employee* pEmpleado;
    int retorno;
    char respuesta;
    char auxId[10];

    if(pArrayListEmployee == NULL)
      {
        printf("ERROR. No se puede acceder a la lista de empleados o la misma esta vacia.\n");
        retorno=-1;
    }
    /*else if(ll_isEmpty(pArrayListEmployee)!= 0)
      {
        retorno=1;
        printf("Debe cargar los datos a memoria para operar.\n");
    }*///TODO mismo ll_isempty
    else if(employee_loadNew(nombre,&horasTrabajo,&sueldo,pArrayListEmployee) == 0)
      {
        nuevoId = emp_generarId();
        pEmpleado = employee_newParametrosNumerico(nuevoId,nombre,horasTrabajo,sueldo);
        if(pEmpleado != NULL)
        {
            employee_printEmpleado(pEmpleado);
            if(utn_getContinue(&respuesta,"Desea dar de alta este empleado?(y/n)","Incorrecto.\n",2)== 0 && (respuesta == 'y' || respuesta=='Y')){
                sprintf(auxId,"%d",nuevoId);
                dict_insert(pArrayListEmployee, auxId, pEmpleado);
                printf("Empleado guardado correctamente.\n");
                retorno=0;
            }
        }
    }
    else
    {
        printf("ERROR. No se pudo dar de alta al empleado .\n");
        retorno=-1;
    }

    return retorno;
}


int controller_editEmployee(Dictionary* pArrayListEmployee)
{
    int idElegido;
    Employee* pEmpleado;
    char respuesta;
    int opcion;
    char nombre[SIZE_NAME];
    int horas;
    int sueldo;
    char nombreNuevo[SIZE_NAME];
    int horasNuevo;
    int sueldoNuevo;
    int retorno=-1;
    char auxIdChar[50];

    if(pArrayListEmployee != NULL /*&& ll_isEmpty(pArrayListEmployee) == 0*/)
    {
        if(utn_getNumero(&idElegido,"Ingrese ID del empleado a modificar:","Valor incorrecto.\n",1,2000,2)==1)
        {
            sprintf(auxIdChar,"%d",idElegido);
            pEmpleado =(Employee*) dict_get(pArrayListEmployee,auxIdChar);
            printf("  ID\t      Nombre\t   Horas  Salario\n");
            employee_printEmpleado(pEmpleado);
            if(utn_getContinue(&respuesta,"Desea modificar este empleado?(y/n)","Incorrecto.\n",2)== 0 && (respuesta == 'y' || respuesta=='Y'))
            {
                employee_getNombre(pEmpleado,nombre);
                employee_getHorasTrabajadas(pEmpleado,&horas);
                employee_getSueldo(pEmpleado,&sueldo);
                do
                {
                    if(utn_getNumero(&opcion,"\nElija el campo a modificar:\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nElija una opcion:","Opcion ncorrecta.\n",1,4,2)==1)
                    {
                        switch(opcion)
                        {
                        case 1:
                            if(utn_getNombre(nombreNuevo,"Ingrese nuevo nombre:","Valor incorrecto.\n",SIZE_NAME,2) == 0)
                            {
                                employee_setNombre(pEmpleado,nombreNuevo);
                            }
                            break;
                        case 2:
                            if(utn_getNumero(&horasNuevo,"Ingrese horas trabajadas:","Valor incorrecto.\n",1,2000,2) == 1)
                            {
                                employee_setHorasTrabajadas(pEmpleado,horasNuevo);
                            }
                            break;
                        case 3:
                            if(utn_getNumero(&sueldoNuevo,"Ingrese nuevo sueldo:","Valor incorrecto.\n",1,200000,2) == 1)
                            {
                                employee_setSueldo(pEmpleado,sueldoNuevo);
                            }
                            break;
                        }
                    }
                }
                while(opcion != 4);
                printf("  ID\t      Nombre\t   Horas  Salario\n");
                employee_printEmpleado(pEmpleado);
                if(utn_getContinue(&respuesta,"Confirma la modificacion?(y/n)","Respuesta incorrecta",2)== 0 && (respuesta == 'y' || respuesta== 'Y'))
                {
                    printf("\nEmpleado modificado correctamente.\n");
                    retorno=0;
                }
                else
                {
                    employee_setNombre(pEmpleado,nombre);
                    employee_setHorasTrabajadas(pEmpleado,horas);
                    employee_setSueldo(pEmpleado,sueldo);
                    printf("\nNo se hizo la modificacion de empleado.\n");
                    retorno=1;
                }
            }else{
                retorno = 1;
                printf("\nNo se modifico el empleado.\n");
            }
        }
        else
          {
            printf("\nNo existe empleado con la ID ingresada.\n");
          }

    }
    else
      {
        printf("\nERROR. No se puede hacer la operacion.\n");
      }
    return retorno;
}

int controller_removeEmployee(Dictionary* pArrayListEmployee)
{
    int idElegido;
    char auxIdChar[50];
    Employee* pEmpleado;
    char respuesta;
    int retorno=-1;

    if(pArrayListEmployee != NULL/* && ll_isEmpty(pArrayListEmployee) == 0*/)
    {
        if(utn_getNumero(&idElegido,"Ingrese ID del empleado a borrar:","Valor incorrecto.\n",1,2000,2)==1)
        {
            sprintf(auxIdChar,"%d",idElegido);
            pEmpleado =(Employee*) dict_get(pArrayListEmployee,auxIdChar);
            employee_printEmpleado(pEmpleado);

            if(utn_getContinue(&respuesta,"Desea eliminar este empleado?(y/n)","Incorrecto.\n",2)== 0 && (respuesta=='y' || respuesta == 'Y'))
            {
                employee_delete(pEmpleado);
                dict_remove(pArrayListEmployee,auxIdChar);
                printf("\nEmpleado eliminado correctamente.\n");
                retorno=0;
            }
            else
            {
                printf("\nNo se elimino el empleado .\n");
                retorno = 1;
            }
        }
    }
    else
      {
        printf("ERROR. No se puede hacer la operacion.\n");
      }

    return retorno;
}


int controller_ListEmployee(Dictionary* pArrayListEmployee)
{
    Employee* pEmpleado;
    int longitud;
    int i;
    int retorno=-1;
    LinkedList* listaEmpleados;

    listaEmpleados=dict_getValues(pArrayListEmployee);
    if(listaEmpleados != NULL && ll_isEmpty(listaEmpleados) == 0)
    {
        longitud = ll_len(listaEmpleados);
        printf("  ID\t      Nombre\t   Horas  Salario\n");
        for(i=0; i < longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(listaEmpleados,i);
            employee_printEmpleado(pEmpleado);
        }
        printf("Cantidad de empleados:%d\n",longitud);
        retorno=0;
    }
    else
      {
        printf("La lista esta vacia o no ha sido cargada.\n");
      }
    ll_clear(listaEmpleados);
    ll_deleteLinkedList(listaEmpleados);
    return retorno;
}


int controller_sortEmployee(Dictionary* pArrayListEmployee)
{
    int retorno=-1;
    int opcion;
    int orden;
    LinkedList* linkList;
    linkList= dict_getValues(pArrayListEmployee);

    if(pArrayListEmployee != NULL  && ll_isEmpty(linkList) == 0){
        if(utn_getNumero(&opcion,
                         "\nElija un criterio de ordenamiento:\n"
                         "1.ID.\n"
                         "2.Nombre.\n"
                         "3.Horas trabajadas.\n"
                         "4.Sueldo.\nOpcion:","Opcion Incorrecta.\n",1,4,2)==1 &&
                            utn_getNumero(&orden,"\nElija el orden:\n0.Descendente\n1.Ascendente\n2.Salir\nOpcion:","\nOpcion Incorrecta.\n",0,2,2)==1 && orden != 2)
          {
            switch(opcion){
                case 1:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(linkList,employee_CompareById,orden);
                    controller_printLinkedlistEmployee(linkList);
                    break;
                case 2:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(linkList,employee_CompareByName,orden);
                    controller_printLinkedlistEmployee(linkList);
                    break;
                case 3:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(linkList,employee_CompareByHours,orden);
                    controller_printLinkedlistEmployee(linkList);
                    break;
                case 4:
                  printf("\nSe esta realizando el ordenamiento. Aguarde un instante...\n");
                    ll_sort(linkList,employee_CompareBySalary,orden);
                    controller_printLinkedlistEmployee(linkList);
                    break;
                default:
                    printf("No se hicieron cambios.\n");
                    retorno=1;
                    break;
            }
            printf("\nLa lista fue ordenada correctamente.\n");
            retorno=0;
          }
        else {
              printf("\nNO se modificó el ordenamiento.\n");
             }
    }
    else {
          printf("\nNo hay datos cargados.\n");
         }
    ll_clear(linkList);
    ll_deleteLinkedList(linkList);
    return retorno;
}


int controller_saveAsText(char* path, Dictionary* pArrayListEmployee)
{
    int longitud;
    int i;
    int id;
    char nombre[SIZE_NAME];
    int horasTrabajo;
    int sueldo;
    int retorno=-1;
    FILE* pFile = NULL;
    Employee* pEmpleado;
    LinkedList* listaEmpleados;

    pFile= fopen(path,"w");

    if(path != NULL && pArrayListEmployee != NULL && pFile != NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajo,sueldo\n");
        // Obtengo empleados del diccionario e imprimo sus datos
        listaEmpleados=dict_getValues(pArrayListEmployee);
        longitud=ll_len(listaEmpleados);
        //Escribo cada empleado en una linea del archivo
        for(i=0; i< longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(listaEmpleados,i);
            if(pEmpleado!=NULL){
            employee_getId(pEmpleado,&id);
            employee_getNombre(pEmpleado,nombre);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajo);
            employee_getSueldo(pEmpleado,&sueldo);
            fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajo,sueldo);
            }
        }
        printf("\nDatos guardados en archivo de texto.\n");
        ll_clear(listaEmpleados);
        ll_deleteLinkedList(listaEmpleados);
        retorno=0;
    }
    fclose(pFile);
    return retorno;
}


int controller_saveAsBinary(char* path, Dictionary* pArrayListEmployee)
{
    int longitud;
    FILE* pFile = NULL;
    int i;
    Employee* pEmpleado;
    int retorno=-1;
    LinkedList* listaEmpleados;


    pFile= fopen(path,"wb");
    if(path != NULL)
      {
    // Obtengo empleados del diccionario e imprimo sus datos
    listaEmpleados=dict_getValues(pArrayListEmployee);
    longitud=ll_len(listaEmpleados);
    //Escribo cada empleado en una linea del archivo
      if(pArrayListEmployee != NULL && pFile != NULL)
      {

          for(i=0; i < longitud; i++)
          {
              pEmpleado =(Employee*) ll_get(listaEmpleados,i);
              fwrite(pEmpleado,sizeof(Employee),1,pFile);
          }
          printf("\nDatos guardados en archivo de binario.\n");
          retorno=0;
          ll_clear(listaEmpleados);
          ll_deleteLinkedList(listaEmpleados);
      }
      }
    fclose(pFile);
    return retorno;
}

int controller_close(Dictionary* pArrayListEmployee)
{
    int retorno=-1;
    printf("Cerrando el programa...\n");
    if(pArrayListEmployee !=NULL){
    dict_deleteDictionary(pArrayListEmployee);
    retorno=0;
    }
    printf("\t ADIOS!.\n");
    return retorno;
}

static int controller_printLinkedlistEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    int longitud;
    int i;
    int retorno=-1;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee) == 0)
    {
        longitud = ll_len(pArrayListEmployee);
        printf("  ID\t      Nombre\t   Horas  Salario\n");
        for(i=0; i < longitud; i++)
        {
            pEmpleado =(Employee*) ll_get(pArrayListEmployee,i);
            employee_printEmpleado(pEmpleado);
        }
        printf("Cantidad de empleados:%d\n",longitud);
        retorno=0;
    }
    else
      {
        printf("La lista esta vacia o no ha sido cargada.\n");
      }

    return retorno;
}
#endif // employee_H_INCLUDED
