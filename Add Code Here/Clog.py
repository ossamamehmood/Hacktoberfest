import logging

class Clog():
  # Set up a custom logger that's modular, extensible, and easy to use.
  # Make use of various SDKs and APIs to make the logging experience as easy as possible.
  # Use the logging module to log to a file.

  import logging

  def __init__(self, log_file_name='Clog.log'):
    self.log_file_name = log_file_name
    self.logger = logging.getLogger(__name__)
    self.logger.setLevel(logging.DEBUG)
    self.formatter = logging.Formatter('%(asctime)s:%(name)s:%(levelname)s:%(message)s')
    self.file_handler = logging.FileHandler(self.log_file_name)
    self.file_handler.setFormatter(self.formatter)
    self.logger.addHandler(self.file_handler)
    self.logger.info(f'Logging to {self.log_file_name} initialized.')

  def log(self, message, level='info'):
    if level == 'info':
      self.logger.info(message)
    elif level == 'warning':
      self.logger.warning(message)
    elif level == 'error':
      self.logger.error(message)
    elif level == 'critical':
      self.logger.critical(message)
    else:
      self.logger.debug(message)

  def test(self):
    self.log('Testing Clog...')
    self.log('info', 'info')
    self.log('warning', 'warning')
    self.log('error', 'error')
    self.log('critical', 'critical')
    self.log('debug', 'debug')

if __name__ == "__main__":
  clog = Clog()
  clog.test()