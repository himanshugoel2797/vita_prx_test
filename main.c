#include <stdint.h>
#include <stdio.h>
#include <psp2/kernel/modulemgr.h>

int main() {

	FILE *outData = fopen("ux0:test_out.bin", "wb");

	uint32_t retval = 0;
	int32_t err = sceKernelLoadStartModule("app0:module.prx", 0, NULL, 0, NULL, &retval);

  	fwrite(&err, 1, 4, outData);
	fwrite(&retval, 1, 4, outData);

  	fclose(outData);
	sceKernelExitProcess(0);
}
