import React, { useState } from "react";
import "../Styles/reservation.css";
import "../Styles/rangePicker.css";
import dayjs from "dayjs";
import { Button, Modal } from "antd";
import { Checkbox, Form, Input } from "antd";
import Dropdown from "react-bootstrap/Dropdown";
import axios from "axios";
import { DatePicker, Space, Select } from "antd";

const baseURL = "http://localhost:3000/add-customer";

const { RangePicker } = DatePicker;
const onFinish = (values) => {
  console.log("Success:", values);
};
const onFinishFailed = (errorInfo) => {
  console.log("Failed:", errorInfo);
};
function ReservationForm() {
  const disabledDate = (current) => {
    return current && current < dayjs().startOf("day");
  };

  const getPriceForDate = () => {
    return "₹2500";
  };

  const renderCell = (date) => {
    const price = getPriceForDate(date);

    return (
      <div className="cell-render-custom">
        <div className="cell-date">{date.date()}</div>
        <div className="cell-price">{price}</div>
      </div>
    );
  };
  const [isModalOpen, setIsModalOpen] = useState(false);

  // const [isDetailsModalOpen, setIsDetailsModalOpen] = useState(false);

  const showModal = () => {
    setIsModalOpen(true);
  };
  // const showDetailsModal = () => {
  //   setIsDetailsModalOpen(true);
  // };

  const handleCancel = () => {
    setIsModalOpen(false);
  };


  // const handleDetailsOk = () => {
  //   setIsDetailsModalOpen(false);
  // };
  // const handleDetailsCancel = () => {
  //   setIsDetailsModalOpen(false);
  // };

  const [user, setUser] = useState({
    name: "",
    checkin: "",
    checkOut: "",
    mobno: "",
    email: "",
    roomType: "AC Standard Suite",
  }); 

  const { name, checkin, checkOut, mobno, email, roomType } = user;

  const onInputChange = (e) => {
    console.log("fired");

    setUser({ ...user, [e.target.name]: e.target.value });
  };
  const onInputChangeCheckInDate = (date, dateString) => {
    if (date) {
      const isoDateString = date.toISOString();
      setUser({ ...user, checkin: isoDateString });
    }
  };
  
  const onInputChangeCheckOutDate = (date, dateString) => {
    if (date) {
      const isoDateString = date.toISOString();
      setUser({ ...user, checkOut: isoDateString });
    }
  };
  const onInputChangeSelect = (value) => {
    setUser({ ...user, roomType: value });
  };
  const [value, setValue] = useState([null, null]);

  const start = value[0];
  const end = value[1];
  const onChangeRange = (value) => {
    setValue(value);
    setUser({
      ...user,
      checkin: value[0].toISOString(),
      checkOut: value[1].toISOString(),
    });
    console.log(user)
  };
  const onSubmit = async (e) => {
    e.preventDefault();
    setIsModalOpen(false);
    // setIsDetailsModalOpen(true);
    console.log("aaaaaa-");
    console.log(user);
    await axios.post("http://localhost:3000/add-customer",user).then((response) => {
      console.log(response.status, response.data.token);});
  };
  return (
    <div className="form">
      <div className="form-elem">
        <div class="formbt">
          <Dropdown>
            <Dropdown.Toggle className="custom-dropdown-toggle">
              View Rooms
            </Dropdown.Toggle>
            <Dropdown.Menu>
              <Dropdown.Item href="/ViewNonACRoom">
                View Non-AC Room
              </Dropdown.Item>
              <Dropdown.Item href="/ViewNonACStandard">
                View Non-AC Standard Suit Room
              </Dropdown.Item>
              <Dropdown.Item href="/ViewNonACSuite">
                View Non-AC Suite Room
              </Dropdown.Item>
              <Dropdown.Item href="/ViewACSuitRoom">
                View AC Suit Room
              </Dropdown.Item>
              <Dropdown.Item href="/ViewACNormalRoom">
                View AC Normal Room
              </Dropdown.Item>
              <Dropdown.Item href="/ViewACStandard">
                View AC Standard Suit Room
              </Dropdown.Item>
            </Dropdown.Menu>
          </Dropdown>
        </div>
        <div id="formwrapper">
          <RangePicker
            className="rangepickerForm"
            disabledDate={disabledDate}
            cellRender={renderCell}
            value={value}
            onChange={onChangeRange}
          />
        </div>

        <div className="formbtns">
          <Modal
          
            title="Booking Form"
            open={isModalOpen}
            onOk={onSubmit}
            onCancel={handleCancel}
          >
            <Form
              name="basic"
              labelCol={{
                span: 8,
              }}
              wrapperCol={{
                span: 16,
              }}
              style={{
                maxWidth: 600,
              }}
              initialValues={{
                remember: true,
              }}
              onFinish={onFinish}
              onFinishFailed={onFinishFailed}
              autoComplete="off"
            >
              <Form.Item
                label="Please Enter Your Name :"
                name="username"
                rules={[
                  {
                    required: true,
                    message: "Please input your username!",
                  },
                ]}
              >
                <Input
                  type={"text"}
                  className="Res-input"
                  name="name"
                  value={name}
                  onChange={(e) => onInputChange(e)}
                />
              </Form.Item>

              <Form.Item
                label="Email :"
                name="Email"
                rules={[
                  {
                    required: true,
                    message: "Please input your email!",
                    type: "email",
                  },
                ]}
              >
                <Input
                  className="Res-input"
                  name="email"
                  value={email}
                  onChange={(e) => onInputChange(e)}
                />
              </Form.Item>

              <Form.Item
                label="Mobile No :"
                name="mobNo"
                rules={[
                  {
                    required: true,
                    message: "Please input your Mob No!",
                  },
                ]}
              >
                <Input
                  className="Res-input"
                  name="mobno"
                  value={mobno}
                  onChange={(e) => onInputChange(e)}
                />
              </Form.Item>
              <Form.Item
        label="CheckIn date :"
        name="checkin"
        rules={[
          {
            required: true,
            message: "Please input your checkInDate!",
          },
        ]}
      >
        <DatePicker
          className="Res-input"
          name="checkin"
          value={user.checkin}
          onChange={(date, dateString) => onInputChangeCheckInDate(date, dateString)}
        />
      </Form.Item>
      <Form.Item
        label="CheckOut date :"
        name="checkOut"
        rules={[
          {
            required: true,
            message: "Please input your checkOutDate!",
          },
        ]}
      >
        <DatePicker
          className="Res-input"
          name="checkOut"
          value={user.checkOut}
          onChange={(date, dateString) => onInputChangeCheckOutDate(date, dateString)}
        />
      </Form.Item>
              <Form.Item
                label="Type Of Room:"
                name="roomType"
                rules={[
                  {
                    required: true,
                    message: "Please select a room type!",
                  },
                ]}
              >
                <Select
                  name="roomType"
                  defaultValue="AC Standard Suite"
                  className="Res-input"
                  onChange={(e) => onInputChangeSelect(e)}
                  options={[
                    {
                      value: "Non AC",
                      label: "Non AC",
                    },
                    {
                      value: "Non AC Suite",
                      label: "Non AC Suite",
                    },
                    {
                      value: "AC Normal",
                      label: "AC Normal",
                    },{
                      value: "AC Standard Suite",
                      label: "AC Standard Suite",
                    },{
                      value: "AC Suite",
                      label: "AC Suite",
                    },
                    
                  ]}
                />
              </Form.Item>
            </Form>
          </Modal>

          <button className="formbtn" id="btnsub" onClick={showModal} type="submit">
            BOOK NOW!
          </button>
          <button className="formbtn" type="" >
            MANAGE RESERVATIONS
          </button>
        </div>
      </div>

      <div className="formText">
        For bookings or queries, reach us at +91- 95 35 49 59 38
      </div>
    </div>
  );
}

export default ReservationForm;
