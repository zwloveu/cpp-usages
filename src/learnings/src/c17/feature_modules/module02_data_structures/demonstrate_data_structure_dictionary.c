#include "c17/feature_modules/module02_data_structures/demonstrate_data_structure_dictionary.h"

void demonstrate_data_structure_dictionary_basic()
{
    // #include <stdio.h>
    // #include <stdlib.h>
    // #include "dict.h"
    // #include "dict_insert.h"
    // #include "function1.h"
    // #include "function2.h"
    // #include "function3.h"
    // #include "function4.h"

    // // 注册所有功能和数据到字典表
    // void register_items(Dictionary* dict) {
    //     // 插入函数（字符串键 -> 函数值）
    //     dict_insert_str_key_func_value(dict, "显示系统信息", function1);
    //     dict_insert_str_key_func_value(dict, "计算简单加法", function2);
    //     dict_insert_str_key_func_value(dict, "显示欢迎信息", function3);
    //     dict_insert_str_key_func_value(dict, "显示当前时间", function4);

    //     // 插入其他类型键值对
    //     dict_insert_int_key_int_value(dict, 100, 2024);           // 整数键 -> 整数值（版本年份）
    //     dict_insert_str_key_int_value(dict, "版本号", 1);          // 字符串键 -> 整数值
    //     dict_insert_int_key_str_value(dict, 200, "编程助手");      // 整数键 -> 字符串值（作者）
    //     dict_insert_str_key_str_value(dict, "版权", "MIT");        // 字符串键 -> 字符串值
    //     dict_insert_char_key_float_value(dict, 'v', 1.0f);         // 字符键 -> 浮点数值（版本）
    //     dict_insert_float_key_str_value(dict, 3.14f, "圆周率");    // 浮点键 -> 字符串值
    // }

    // // 显示键的内容
    // void print_key(const DictKey* key) {
    //     if (!key) return;

    //     printf("[");
    //     switch (key->type) {
    //         case KEY_TYPE_INT:
    //             printf("整数键: %d", *(int*)key->data);
    //             break;
    //         case KEY_TYPE_STRING:
    //             printf("字符串键: \"%s\"", (const char*)key->data);
    //             break;
    //         case KEY_TYPE_POINTER:
    //             printf("指针键: %p", key->data);
    //             break;
    //         case KEY_TYPE_FLOAT:
    //             printf("浮点键: %.2f", *(float*)key->data);
    //             break;
    //         case KEY_TYPE_CHAR:
    //             printf("字符键: '%c'", *(char*)key->data);
    //             break;
    //         default:
    //             printf("未知类型键");
    //     }
    //     printf("]");
    // }

    // // 显示值的内容
    // void print_value(const DictValue* value) {
    //     if (!value) return;

    //     printf("[");
    //     switch (value->type) {
    //         case VALUE_TYPE_INT:
    //             printf("整数: %d", *(int*)value->data);
    //             break;
    //         case VALUE_TYPE_STRING:
    //             printf("字符串: \"%s\"", (const char*)value->data);
    //             break;
    //         case VALUE_TYPE_POINTER:
    //             printf("指针: %p", value->data);
    //             break;
    //         case VALUE_TYPE_FLOAT:
    //             printf("浮点: %.2f", *(float*)value->data);
    //             break;
    //         case VALUE_TYPE_FUNCTION:
    //             printf("函数指针");
    //             break;
    //         case VALUE_TYPE_CHAR:
    //             printf("字符: '%c'", *(char*)value->data);
    //             break;
    //         default:
    //             printf("未知类型值");
    //     }
    //     printf("]");
    // }

    // // 显示功能菜单
    // int show_function_menu(Dictionary* dict) {
    //     printf("\n===== 功能菜单 =====\n");
    //     size_t func_count = 0;
    //     DictEntry* func_entries[100]; // 存储函数条目指针

    //     // 收集所有函数类型的条目
    //     for (size_t i = 0; i < dict->capacity; i++) {
    //         DictEntry* current = dict->entries[i];
    //         while (current) {
    //             if (current->value->type == VALUE_TYPE_FUNCTION &&
    //                 current->key->type == KEY_TYPE_STRING) {
    //                 func_entries[func_count++] = current;
    //             }
    //             current = current->next;
    //         }
    //     }

    //     // 显示函数菜单
    //     for (size_t i = 0; i < func_count; i++) {
    //         printf("%zu. %s\n", i + 1, (const char*)func_entries[i]->key->data);
    //     }

    //     printf("%zu. 显示所有字典数据\n", func_count + 1);
    //     printf("%zu. 退出程序\n", func_count + 2);
    //     printf("请选择功能 (1-%zu): ", func_count + 2);

    //     int choice;
    //     scanf("%d", &choice);

    //     // 如果选择了函数，执行它
    //     if (choice >= 1 && choice <= (int)func_count) {
    //         void (*func)() = (void (*)())func_entries[choice - 1]->value->data;
    //         printf("\n--- 执行: %s ---\n", (const char*)func_entries[choice - 1]->key->data);
    //         func();
    //         return -1; // 表示已执行函数
    //     }

    //     return choice;
    // }

    // // 显示所有字典数据
    // void show_all_items(Dictionary* dict) {
    //     if (!dict) return;

    //     printf("\n===== 字典中的所有数据 =====\n");
    //     printf("共有 %zu 个条目, 容量: %zu\n", dict->count, dict->capacity);
    //     printf("----------------------------\n");

    //     for (size_t i = 0; i < dict->capacity; i++) {
    //         if (dict->entries[i]) {
    //             printf("索引 %zu 处的链表:\n", i);
    //             DictEntry* current = dict->entries[i];
    //             size_t j = 0;

    //             while (current) {
    //                 printf("  节点 %zu: ", j++);
    //                 print_key(current->key);
    //                 printf(" -> ");
    //                 print_value(current->value);

    //                 // 演示从键访问值
    //                 if (current->key->value_ptr == current->value) {
    //                     printf(" (键值关联正常)");
    //                 } else {
    //                     printf(" (键值关联异常)");
    //                 }

    //                 printf("\n");
    //                 current = current->next;
    //             }
    //         }
    //     }
    // }

    // int main() {
    //     // 初始化字典表
    //     Dictionary* dict = dict_init(4);
    //     if (!dict) {
    //         fprintf(stderr, "无法初始化字典表\n");
    //         return 1;
    //     }

    //     // 注册所有项目
    //     register_items(dict);

    //     // 主循环
    //     while (1) {
    //         int choice = show_function_menu(dict);

    //         // 如果是函数执行后的返回值，直接继续循环
    //         if (choice == -1) {
    //             continue;
    //         }

    //         size_t func_count = 0;
    //         // 计算函数类型的条目数量
    //         for (size_t i = 0; i < dict->capacity; i++) {
    //             DictEntry* current = dict->entries[i];
    //             while (current) {
    //                 if (current->value->type == VALUE_TYPE_FUNCTION &&
    //                     current->key->type == KEY_TYPE_STRING) {
    //                     func_count++;
    //                 }
    //                 current = current->next;
    //             }
    //         }

    //         // 检查用户选择
    //         if (choice < 1 || choice > (int)(func_count + 2)) {
    //             printf("无效的选择，请重试！\n");
    //             continue;
    //         }

    //         // 退出程序
    //         if (choice == (int)(func_count + 2)) {
    //             printf("感谢使用，再见！\n");
    //             break;
    //         }

    //         // 显示所有字典数据
    //         if (choice == (int)(func_count + 1)) {
    //             show_all_items(dict);
    //         }
    //     }

    //     // 清理资源
    //     dict_destroy(dict);
    //     return 0;
    // }
}
