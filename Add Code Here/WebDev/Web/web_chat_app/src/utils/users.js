require("../db/mongoose");
const User = require("../../models/user");

const addUser = (username, channel, id) => {
  if (!username || !channel || !id) {
    //console.log('username , channel cant be blank.');
    throw new Error("USERNAME OR CHANNEL CAN'T BE BLANK!!!");
  }

  User.findOne(
    { username: username, channel: channel },
    (err, existingUser) => {
      //console.log(existingUser);
      if (existingUser || err) {
        return err;
      } else {
        const user = new User({ username: username, channel: channel, id: id });
        user.save();
      }
    }
  );
};

const getUser = (id, callback) => {
  User.findOne({ id: id }, (err, user) => {
    if (user) return callback(null, user);
    else if (err) return callback(err);
    else return callback();
  });
};

const removeUser = (id, callback) => {
  User.findOneAndDelete({ id: id }, (err, user) => {
    if (user) return callback(null, user);
    else if (err) return callback(err);
    else return callback();
  });
};

const getUserListInChannel = (channel, callback) => {
  User.find({ channel: channel }, (err, users) => {
    if (users) return callback(null, users);
    else if (err) return callback(err);
    else return callback();
  });
};

module.exports = {
  addUser,
  getUser,
  removeUser,
  getUserListInChannel,
};
