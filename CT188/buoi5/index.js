$(document).ready(() => {
    // $("#loaded").addClass("loaded");
    var tooltipTriggerList = [].slice.call(document.querySelectorAll('[data-bs-toggle="tooltip"]'))
    var tooltipList = tooltipTriggerList.map(function (tooltipTriggerEl) {
        return new bootstrap.Tooltip(tooltipTriggerEl)
    })
    $("#table").bootstrapTable({
        columns: [{
            field: "id",
            title: "Mã khóa học"
        },
        {
            field: "name",
            title: "Khóa học"
        },
        {
            field: "date",
            title: "Ngày khai giảng"
        }
        ],
        data: [
            {
                id: "CB001", name: "Thiên Văn học Cơ Bản", date: "30/11/2021"
            },
            {
                id: "VT002", name: "Vũ Trụ Học Cơ Bản", date: "01/12/2021"
            },
            {
                id: "QS001", name: "Học Máy Và Thiên Văn Học", date: "15/12/2021"
            }
        ]
    })
})
