/**
 * -------------------------------------------------------------------------
 *                                   AurorOS
 * (c) 2022-2025 Interpuce
 * 
 * You should receive AurorOS license with this source code. If not - check:
 *  https://github.com/Interpuce/AurorOS/blob/main/LICENSE.md
 * -------------------------------------------------------------------------
 */

#define COLOR_1 0x47
#define COLOR_2 0x4F
#define COLOR_3 0x44

#include <msg.h>
#include <types.h>
#include <screen.h>
#include <panic.h>
   

void invalidop(const char *operation, void (*handler)()) {

    if (!handler) {
        kernelpanic("INVALIDOP_HANDLER_IS_NULL/UNSAFE_TO_CONTINUE");
    }

    paintscreen(COLOR_3);
    println(" ", COLOR_1);
    println(" Invalid operation!", COLOR_2);
    println(" ", COLOR_1);
    println(" The requested operation could not be performed safely. \n The error is not fatal, though. \n You can resume the session after the issue is handled. \n", COLOR_1);
    println(" Depending on the cause, it might take several seconds or several minutes. \n AurorOS will notify you when it's possible to resume the session.", COLOR_1);
    println("\n \n Operation which caused the issue: \n ", COLOR_1);
    println(" ", COLOR_1);
    println(operation, COLOR_2);

    handler(); /* handler is situated here due to the synchronous nature of C functions. We want to the text above to be already displayed when the handler is called. We don't want the last line
		to be called before handler finishes executing. */

    print("\n", COLOR_1);
    println(" The error has been handled successfully. \n Type 'clear' and press Enter to return to the console.", COLOR_1);
}