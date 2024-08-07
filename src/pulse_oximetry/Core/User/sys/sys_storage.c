/**
 * @file       sys_storage.h
 * @copyright  Copyright (C) 2019 ITRVN. All rights reserved.
 * @license    This project is released under the Fiot License.
 * @version    v1.0.0
 * @date       2024-08-05
 * @author     Giang Phan Truong
 *             Khanh Nguyen Ngoc
 *             Viet Hoang Xuan
 *
 * @brief      System sevice take responsibility for storing and managing data in FLASH memory
 *
 * @note
 * @example    None
 */

/* Includes ----------------------------------------------------------- */
#include "sys_storage.h"
#include <stdlib.h>
#include "common.h"

/* Private defines ---------------------------------------------------- */
#define SYS_STORAGE_ID_SIZE       (1)   // 1 byte
#define SYS_STORAGE_ID_MAX        (255)
#define SYS_STORAGE_ID_MIN        (0)
#define SYS_STORAGE_ID_ACTIVE     (1)
#define SYS_STORAGE_ID_INACTIVE   (0)

/* Private enumerate/structure ---------------------------------------- */

/* Private macros ----------------------------------------------------- */

/* Public variables --------------------------------------------------- */

/* Private variables -------------------------------------------------- */
static sys_storage_t s_storage_mng[SYS_STORAGE_ID_MAX + 1] = {0};
static uint8_t s_id_mng[SYS_STORAGE_ID_MAX + 1] = {0};

/* Private function prototypes ---------------------------------------- */

/**
 * @brief  Allocate the idenfication for storage segment
 *
 * @note   Can allocate maximum 256 IDs.
 *
 * @return
 *  - the available ID
 */
static uint8_t sys_storage_get_id(void);
static uint8_t sys_storage_get_id_curr_pos_in_arr(uint8_t id);

int comparator(const void* p, const void* q)
{
   int l = ((sys_storage_t*)p)->address;
   int r = ((sys_storage_t*)q)->address;
   return (l - r);
}

/* Function definitions ----------------------------------------------- */
uint32_t sys_storage_init(sys_storage_t *storage, uint32_t start_address, uint32_t size)
{
  __ASSERT(storage != NULL, SYS_STORAGE_ERROR);
  __ASSERT(size < SYS_STORAGE_FLASH_SECTOR_SIZE, SYS_STORAGE_ERROR);
  __ASSERT(size != 0, SYS_STORAGE_ERROR);
  
  storage->id = sys_storage_get_id();

  s_storage_mng[SYS_STORAGE_ID_MIN].id = storage->id;
  s_storage_mng[SYS_STORAGE_ID_MIN].address = start_address;
  s_storage_mng[SYS_STORAGE_ID_MIN].size = size;

  if (storage->id == 0)
  {
    if ((start_address < SYS_STORAGE_FLASH_SECTOR_ADDRESS) ||
       ((start_address + size) >= (SYS_STORAGE_FLASH_SECTOR_ADDRESS + SYS_STORAGE_FLASH_SECTOR_SIZE)))
    {
      s_id_mng[storage->id] = SYS_STORAGE_ID_INACTIVE;
      s_storage_mng[SYS_STORAGE_ID_MIN] = (sys_storage_t){0, 0, 0, 0};
      return SYS_STORAGE_ERROR;
    }
    else
    {
      qsort(s_storage_mng, SYS_STORAGE_ID_MAX + 1, sizeof(sys_storage_t), comparator);
    }
  }
  else
  {
    qsort(s_storage_mng, SYS_STORAGE_ID_MAX + 1, sizeof(sys_storage_t), comparator);
    uint8_t id_curr_pos = sys_storage_get_id_curr_pos_in_arr(storage->id);
    
    if (id_curr_pos == 255)
    {
      if ((s_storage_mng[id_curr_pos].address 
           < (s_storage_mng[id_curr_pos - 1].address + s_storage_mng[id_curr_pos - 1].size)) || 
         ((s_storage_mng[id_curr_pos].address + s_storage_mng[id_curr_pos].size)
           >= (SYS_STORAGE_FLASH_SECTOR_ADDRESS + SYS_STORAGE_FLASH_SECTOR_SIZE)))
      {
        s_id_mng[storage->id] = SYS_STORAGE_ID_INACTIVE;
        s_storage_mng[id_curr_pos] = (sys_storage_t){0, 0, 0, 0};
        qsort(s_storage_mng, SYS_STORAGE_ID_MAX + 1, sizeof(sys_storage_t), comparator);
        return SYS_STORAGE_ERROR;
      }
    }
    else 
    {
      if ((s_storage_mng[id_curr_pos].address 
        < (s_storage_mng[id_curr_pos - 1].address + s_storage_mng[id_curr_pos - 1].size)) ||
       ((s_storage_mng[id_curr_pos].address + s_storage_mng[id_curr_pos].size)
         >= s_storage_mng[id_curr_pos + 1].address))
      {
        s_id_mng[storage->id] = SYS_STORAGE_ID_INACTIVE;
        s_storage_mng[id_curr_pos] = (sys_storage_t){0, 0, 0, 0};
        qsort(s_storage_mng, SYS_STORAGE_ID_MAX + 1, sizeof(sys_storage_t), comparator);
        return SYS_STORAGE_ERROR;
      }
    }
  }

  s_id_mng[storage->id] = SYS_STORAGE_ID_ACTIVE;
  storage->address = start_address;

  uint32_t ret = BSP_FLASH_OK;
  ret = bsp_flash_write(storage->address, &storage->id, SYS_STORAGE_ID_SIZE);
  __ASSERT(ret == BSP_FLASH_OK, SYS_STORAGE_FAILED);

  storage->size = size;
  storage->space_left = size - SYS_STORAGE_ID_SIZE;

  return SYS_STORAGE_OK;
}

uint32_t sys_storage_import(sys_storage_t *storage, void *data, uint32_t size)
{
  __ASSERT(storage != NULL, SYS_STORAGE_ERROR);
  __ASSERT(data != NULL, SYS_STORAGE_ERROR);
  __ASSERT(size <= storage->space_left, SYS_STORAGE_ERROR);
  __ASSERT(size != 0, SYS_STORAGE_ERROR);
  __ASSERT(s_id_mng[storage->id] == SYS_STORAGE_ID_ACTIVE, SYS_STORAGE_ERROR);

  uint32_t ret = BSP_FLASH_OK;
  ret = bsp_flash_write(storage->address + (storage->size - storage->space_left), data, size);
  __ASSERT(ret == BSP_FLASH_OK, SYS_STORAGE_FAILED);
  storage->space_left -= size;

  return SYS_STORAGE_OK;
}

uint32_t sys_storage_export(sys_storage_t *storage, void *data, uint32_t size)
{
  __ASSERT(storage != NULL, SYS_STORAGE_ERROR);
  __ASSERT(data != NULL, SYS_STORAGE_ERROR);
  __ASSERT(size <= (storage->size - storage->space_left), SYS_STORAGE_ERROR);
  __ASSERT(size != 0, SYS_STORAGE_ERROR);
  __ASSERT(s_id_mng[storage->id] == SYS_STORAGE_ID_ACTIVE, SYS_STORAGE_ERROR);

  uint32_t ret = BSP_FLASH_OK;
  ret = bsp_flash_read(storage->address + SYS_STORAGE_ID_SIZE, data, size);
  __ASSERT(ret == BSP_FLASH_OK, SYS_STORAGE_FAILED);

  return SYS_STORAGE_OK; 
}

uint32_t sys_storage_fully_clean(sys_storage_t *storage)
{
  __ASSERT(storage != NULL, SYS_STORAGE_ERROR);
  __ASSERT(s_id_mng[storage->id] == SYS_STORAGE_ID_ACTIVE, SYS_STORAGE_ERROR);

  // Store backup data to sector 6
  
  uint32_t ret = SYS_STORAGE_OK;
  ret = 
  __ASSERT(ret == SYS_STORAGE_OK, SYS_STORAGE_FAILED);

  return SYS_STORAGE_OK; 
}

uint32_t sys_storage_deinit(sys_storage_t *storage)
{
  __ASSERT(storage != NULL, SYS_STORAGE_ERROR);
  __ASSERT(s_id_mng[storage->id] == SYS_STORAGE_ID_ACTIVE, SYS_STORAGE_ERROR);

  uint32_t ret = BSP_FLASH_OK;
  ret = sys_storage_fully_clean(storage);
  __ASSERT(ret == BSP_FLASH_OK, SYS_STORAGE_FAILED);

  s_id_mng[storage->id] = SYS_STORAGE_ID_INACTIVE;
  
  storage->address = 0;
  storage->size = 0;
  storage->space_left = 0;

  return SYS_STORAGE_OK; 
}

/* Private definitions ------------------------------------------------ */
static uint8_t sys_storage_get_id(void)
{
  for (uint8_t i = SYS_STORAGE_ID_MIN; i <= SYS_STORAGE_ID_MAX; i++)
  {
    if (s_id_mng[i] == SYS_STORAGE_ID_INACTIVE)
    {
      return i;
    }
  }
}

static uint8_t sys_storage_get_id_curr_pos_in_arr(uint8_t id)
{
  for (uint8_t i = SYS_STORAGE_ID_MIN; i <= SYS_STORAGE_ID_MAX; i++)
  {
    if (s_storage_mng[i].id == id)
    {
      return i;
    }
  }
}
/* End of file -------------------------------------------------------- */
