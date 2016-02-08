#include"vector.h"


/**
 * Creates a vector as a dinamic array structure
 * @param nritems initial item capacity
 * @param itemsize the size of an item
 * @return the created vector
 */ 

vector* vector_create(int nritems,size_t itemsize)
{
    if(!itemsize)return NULL;
    
    vector* ar=malloc(sizeof(vector));
    
    if(!ar)
    {
        perror("Unable to allocate memmory for vector");
        return NULL;
    }
    
    ar->size=0;
    if(!nritems)
    {
        nritems=10; //default
    }
    
    ar->internal_capacity=nritems;
    ar->item_size=itemsize;
    ar->data=malloc(ar->internal_capacity*ar->item_size);
    if(!ar->data)
    {
        free(ar);
        perror("Unable to allocate memmory!");
        return NULL;
    }
    
    return ar;
}




/**
 *It clear the memmory allocated for the vector
 * @param ar the vector
 */
void vector_free(vector** ar)
{
    if(*ar)
    {
        free((*ar)->data);
        free(*ar);
        *ar=NULL;
    }
}


/**
 * It expands the internal capacity of the vector to double the size
 * @param ar the vector
 * @return 1 if successful 0 if not
 */

int vector_expand(vector* ar)
{
    if(ar)
    {
        void** temp=(void**)realloc(ar->data,ar->internal_capacity*ar->item_size*2);
        if(temp!=NULL)
        {
            
            ar->data=temp;
            ar->internal_capacity=ar->internal_capacity*2;
            return 1;
        }
        else
        {
            perror("Unable to expand the vector");
            return 0;
        }
        
    }
    return 0;
}


/**
 * Inserts a value into the vector.it does expand the vector if neccesary.
 * @param ar is the vector
 * @param item is the data 
 * @return 1 in case of success and 0 if there is an error
 */
 
 
int vector_insert(vector* ar, void* item)
{
    if(ar && item)
    {
        if(ar->size>=ar->internal_capacity)
        {
            if(!vector_expand(ar))
            {
                return 0;
            }
        }
        
        ar->data[ar->size]=item;
        ar->size++;
        return 1;
        
    }
    return 0;
    
}



/**
 * Retrive a vallue from the vector
 * @param ar  is the vector
 * @param idx is the index of the item that needs to be retrieved
 * @return if found it returns the item if not then NULL
 */
 

void* vector_get(vector* ar,unsigned int idx)
{
    
    if(ar)
    {
        if(idx<ar->size)
        {
           return ar->data[idx];
            
        }
    }
    return NULL;
}



/**
 * Updates one item in the vector (beaware to free the returned data if requiered)
 * @param ar the vector
 * @param idx is the index in the vector
 * @param val is the new value
 * @return  the old value or NULL in case of error
 */


void* vector_update(vector* ar,unsigned int idx,void* val)
{
    if(ar && val)
    {
        if(idx<ar->size)
        {
            void* temp=ar->data[idx];
            ar->data[idx]=val;
            return temp;
        }
    }
    return NULL;
}



/**
 * It removes the item at a specific index in the vector
 * @param ar the vector
 * @param idx is the index
 * @return the old data ( in case it needs to be set free) or NULL in case of error
 */ 
void* vector_remove(vector* ar, unsigned int idx)
{
    
    void* ret=NULL;
    
    if(ar)
    {
        int temp=idx;
        while(1)
        {
            if(temp>=ar->size)
            {
                
                break;
            }
            
            temp++;
            
            ret=ar->data[temp-1];
            
            if(temp>=ar->size)
            {
                
                ar->data[temp-1]=NULL;
            }
            else
            {
                ar->data[temp-1]=ar->data[temp];
            }
            
           
        }
       
        if(ret)
        {
            ar->size--;
           
        }
    
    }
    return ret;

}
