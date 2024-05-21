
bool validate(int param_1)

{
    return param_1 == secret + 0x539;
}

undefined8 show_link(undefined4 param_1)

{
    int iVar1;
    int iVar2;
    size_t sVar3;
    undefined8 uVar4;
    long lVar5;
    undefined8 *puVar6;
    undefined8 *puVar7;
    long in_FS_OFFSET;
    undefined8 local_3018[72];
    undefined local_2dd7;
    undefined2 local_2dd6;
    undefined4 local_2dd4;
    undefined8 auStack_2dd0[439];
    uchar local_2018[4096];
    char local_1018[43];
    undefined auStack_fed[4061];
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    puVar6 = (undefined8 *)&DAT_001020d0;
    puVar7 = local_3018;
    for (lVar5 = 0x48; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
    }
    *(undefined *)puVar7 = *(undefined *)puVar6;
    local_2dd7 = 0;
    local_2dd6 = 0;
    local_2dd4 = 0;
    puVar6 = auStack_2dd0;
    for (lVar5 = 0x1b7; lVar5 != 0; lVar5 = lVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
    }
    sVar3 = strlen((char *)local_3018);
    iVar1 = EVP_DecodeBlock(local_2018, (uchar *)local_3018, (int)sVar3);
    if (iVar1 == -1) {
        fwrite("Failed to decode base64 text\n", 1, 0x1d, stderr);
        ERR_print_errors_fp(stderr);
        uVar4 = 0xffffffff;
    } else {
        iVar1 = proc_encrypt(local_2018, iVar1, key, iv, local_1018, 0);
        if (iVar1 == -1) {
            fwrite("Failed to decrypt links\n", 1, 0x18, stderr);
            ERR_print_errors_fp(stderr);
            uVar4 = 0xffffffff;
        } else {
            sVar3 = strlen(local_1018);
            lVar5 = random();
            iVar1 = (int)(lVar5 % (long)(int)(sVar3 / 0x2b)) * 0x2b;
            auStack_fed[iVar1] = 0;
            iVar2 = validate(param_1);
            if (iVar2 == 0) {
                puts("Better luck next time!");
                uVar4 = 1;
            } else {
                printf("Congrats! Here\'s your link: %s\n", local_1018 + iVar1);
                uVar4 = 0;
            }
        }
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return uVar4;
}

undefined4 main(void)

{
    int iVar1;
    undefined4 uVar2;
    time_t tVar3;
    long lVar4;
    long in_FS_OFFSET;
    undefined4 local_18;
    undefined4 local_14;
    long local_10;

    local_10 = *(long *)(in_FS_OFFSET + 0x28);
    tVar3 = time((time_t *)0x0);
    srandom((uint)tVar3);
    lVar4 = random();
    secret = (undefined4)lVar4;
    printf("Enter your guessed secret (int): ");
    fflush(stdout);
    __isoc99_scanf(&DAT_001030f2, &local_18);
    iVar1 = validate(local_18);
    if (iVar1 == 0) {
        puts("This is incorrect");
        uVar2 = 1;
    } else {
        local_14 = show_link(local_18);
        uVar2 = local_14;
    }
    if (local_10 != *(long *)(in_FS_OFFSET + 0x28)) {
        // WARNING: Subroutine does not return
        __stack_chk_fail();
    }
    return uVar2;
}