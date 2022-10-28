import React from "react";

const Pagination = ({ menusPerPage, totalMenus, paginate }) => {
	const pageNumbers = [];
	for (let i = 1; i <= Math.ceil(totalMenus / menusPerPage); i++) {
		pageNumbers.push(i);
	}
	return (
		<nav className="d-flex justify-content-center bottom-0">
			<ul className="pagination">
				{pageNumbers.map((number) => (
					<li key={number} className="page-item">
						<a onClick={() => paginate(number)} href="#!" className="page-link">
							{number}
						</a>
					</li>
				))}
			</ul>
		</nav>
	);
};

export default Pagination;
