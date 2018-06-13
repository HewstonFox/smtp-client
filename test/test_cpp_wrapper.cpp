#include <err.h>

#include <SMTPMail.h>

/**
 * Main program entry point for the example smtp-client CPP class wrapper.
 *
 * @param[in] argc Number of arguments in @p argv.
 * @param[in] argv String array containing the program name and any optional
 *                 parameters described above.
 * @retval 0 Email has been sent.
 * @retval 1 An error occurred while sending email. Although unlikely, an email
 *           can still get sent even after returning with this error code.
 */
int main(int argc, char *argv[]){
  SMTPMail *mail;

  mail = new SMTPMail();
  try{
    mail->open("localhost", "25", SMTP_SECURITY_NONE, SMTP_DEBUG);
    mail->auth(SMTP_AUTH_NONE, NULL, NULL);
    mail->mail("Email sent using CPP SMTPMail class");
    mail->close();
  }
  catch(SMTPMailException sme){
    errx(1, "Failed to send email: %s\n", sme.what());
  }
  delete mail;

  return 0;
}

